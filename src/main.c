/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 13:58:18 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/23 13:58:24 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_struc(t_cubed *s, char *map_arg)
{
	s->fd = open(map_arg, O_RDONLY);
	if (s->fd == -1)
	{
		ft_putendl_fd(MAP_READ, 2);
		exit(1);
	}
	s->height = -6;
	s->file = (char **)malloc(sizeof (char **) * (ft_fdhei(s->fd) + 1));
	if (!s->file)
		exit(1);
	close(s->fd);
	file_checker(s, map_arg);
}

int	main(int argc, char **argv)
{
	t_cubed	cub3d;

	args_checker(argc, argv);
	init_struc(&cub3d, argv[1]);
	get_player_init(&cub3d);
	init_window(&cub3d);
	return (0);
}

// SI NO HAY JUGADOR EL PROGRAMA PETA