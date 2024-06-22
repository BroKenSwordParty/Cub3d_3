/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:31:32 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/23 00:26:23 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	fill_map(t_cubed *s)
{
	int		i;
	int		j;
	char	*temp;

	i = 5;
	j = -1;
	s->imgs.map = (char **)malloc(sizeof(char *) * (s->height + 1));
	while (s->file[++i])
	{
		s->imgs.map[++j] = ft_strdup(s->file[i]);
		free(s->file[i]);
	}
	s->imgs.map[s->height] = NULL;
	s->file[6] = NULL;
	temp = ft_strchr_array(s->imgs.map);
	if (temp == NULL)
		ft_free_exit(s, 1);
	s->player.dir = *temp;
}

int	check_sides(t_cubed *s, int i, int j)
{
	if (s->imgs.map[i][0] == s->player.dir || s->imgs.map[i][0] == '0')
		return (1);
	if ((s->imgs.map[i][j] == s->player.dir || s->imgs.map[i][j] == '0')
	&& s->imgs.map[i][j + 1] == '\0')
		return (1);
	if (s->imgs.map[i - 1][j] && (s->imgs.map[i - 1][j] != '0'
	&& s->imgs.map[i - 1][j] != '1' && s->imgs.map[i - 1][j] != s->player.dir))
		return (1);
	if (s->imgs.map[i + 1][j] && (s->imgs.map[i + 1][j] != '0'
	&& s->imgs.map[i + 1][j] != '1' && s->imgs.map[i + 1][j] != s->player.dir))
		return (1);
	return (0);
}

int	outer_lines(char *map, char player, int i)
{
	while (map[++i])
	{
		if (map[i] == player || map[i] == '0')
			return (1);
	}
	return (0);
}

void	check_map(t_cubed *s)
{
	int	i;
	int	j;

	i = 0;
	if (outer_lines(s->imgs.map[0], s->player.dir, -1) == 1
		|| outer_lines(s->imgs.map[s->height - 1], s->player.dir, -1) == 1)
		ft_free_exit(s, 1);
	while (++i < (s->height - 1))
	{
		if (ft_strstr(s->imgs.map[i], " 0") || ft_strstr(s->imgs.map[i], "0 ")
			|| ft_strstr(s->imgs.map[i], " N")
			|| ft_strstr(s->imgs.map[i], "N "))
			ft_free_exit(s, 1);
		j = 0;
		while (s->imgs.map[i][++j])
		{
			if (i > 0 && i < (s->height - 1) && (s->imgs.map[i][j] == '0'
				|| s->imgs.map[i][j] == s->player.dir))
			{
				if (check_sides(s, i, j) == 1)
					ft_free_exit(s, 1);
			}
		}
	}
}
