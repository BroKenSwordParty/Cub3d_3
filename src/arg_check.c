/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:22:31 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/22 21:57:09 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	args_checker(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd(ARG_NUM, 2);
		exit (0);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
	{
		ft_putendl_fd(ARG_INV, 2);
		exit(0);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".cub") != 0)
	{
		ft_putendl_fd(ARG_CUB, 2);
		exit(0);
	}
}

void	create_file(t_cubed *s)
{
	char	*line;
	int		i;

	i = -1;
	while (1)
	{
		line = get_next_line(s->fd);
		if (line && line[0] != '\n')
		{
			s->height++;
			s->file[++i] = ft_strdup(line);
			if (!s->file[i])
				break ;
			if (ft_strchr(s->file[i], '\n'))
				*ft_strchr(s->file[i], '\n') = '\0';
		}
		if (!line)
			break ;
		free(line);
	}
	s->file[++i] = '\0';
	close(s->fd);
}

void	file_checker(t_cubed *s, char *map_arg)
{
	s->fd = open(map_arg, O_RDONLY);
	create_file(s);
	fill_and_check(s);
	fill_map(s);
	check_map(s);
}

void	fill_and_check(t_cubed *s)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (s->file[i][0] == 'N' && s->file[i][1] == 'O' &&
			s->file[i][2] == ' ')
			s->imgs.no = ft_substr(s->file[i], 3, (ft_strlen(s->file[i]) - 3));
		if (s->file[i][0] == 'S' && s->file[i][1] == 'O' &&
			s->file[i][2] == ' ')
			s->imgs.so = ft_substr(s->file[i], 3, (ft_strlen(s->file[i]) - 3));
		if (s->file[i][0] == 'E' && s->file[i][1] == 'A' &&
			s->file[i][2] == ' ')
			s->imgs.ea = ft_substr(s->file[i], 3, (ft_strlen(s->file[i]) - 3));
		if (s->file[i][0] == 'W' && s->file[i][1] == 'E' &&
			s->file[i][2] == ' ')
			s->imgs.we = ft_substr(s->file[i], 3, (ft_strlen(s->file[i]) - 3));
		if (s->file[i][0] == 'F' && s->file[i][1] == ' ')
			s->imgs.f = set_color(s->file[i]);
		if (s->file[i][0] == 'C' && s->file[i][1] == ' ')
			s->imgs.c = set_color(s->file[i]);
	}
}

char	**set_color(char *line)
{
	char	**color_data;
	char	*temp;

	color_data = ft_split(line, ',');
	if (color_data && color_data[0])
	{
		temp = ft_substr(color_data[0], 2, ft_strlen(color_data[0]) - 2);
		free(color_data[0]);
		color_data[0] = temp;
	}
	return (color_data);
}
