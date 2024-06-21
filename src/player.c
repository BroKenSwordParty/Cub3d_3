/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 01:28:11 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/20 01:38:48 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	get_player_init_e(t_cubed *s, int i, int j)
{
	s->player.pos_x = j + 0.5;
	s->player.pos_y = i + 0.5;
	s->player.x = j;
	s->player.y = i;
	s->player.dir_x = 1;
	s->player.dir_y = 0;
	s->player.plane_x = 0;
	s->player.plane_y = 0.66;
	s->imgs.map[i][j] = '0';
	return (1);
}

int	get_player_init_w(t_cubed *s, int i, int j)
{
	s->player.pos_x = j + 0.5;
	s->player.pos_y = i + 0.5;
	s->player.x = j;
	s->player.y = i;
	s->player.dir_x = -1;
	s->player.dir_y = 0;
	s->player.plane_x = 0;
	s->player.plane_y = -0.66;
	s->imgs.map[i][j] = '0';
	return (1);
}

int	get_player_init_s(t_cubed *s, int i, int j)
{
	s->player.pos_x = j + 0.5;
	s->player.pos_y = i + 0.5;
	s->player.x = j;
	s->player.y = i;
	s->player.dir_x = 0;
	s->player.dir_y = 1;
	s->player.plane_x = -0.66;
	s->player.plane_y = 0;
	s->imgs.map[i][j] = '0';
	return (1);
}

int	get_player_init_n(t_cubed *s, int i, int j)
{
	s->player.pos_x = j + 0.5;
	s->player.pos_y = i + 0.5;
	s->player.dir_x = 0;
	s->player.x = j;
	s->player.y = i;
	s->player.dir_y = -1;
	s->player.plane_x = 0.66;
	s->player.plane_y = 0;
	s->imgs.map[i][j] = '0';
	return (1);
}
// TERMINADA
void	get_player_init(t_cubed *s)
{
	int		i;
	int		j;
	int		check;

	check = 0;
	i = 0;
	while (++i < (s->height - 1) && check != 1)
	{
		j = 0;
		while (s->imgs.map[i][++j] && check != 1)
		{
			printf("MAP CHAR = %c\n", s->imgs.map[i][j]);
			if (s->imgs.map[i][j] == 'N')
				check = get_player_init_n(s, i, j);
			if (s->imgs.map[i][j] == 'S')
				check = get_player_init_s(s, i, j);
			if (s->imgs.map[i][j] == 'W')
				check = get_player_init_w(s, i, j);
			if (s->imgs.map[i][j] == 'E')
				check = get_player_init_e(s, i, j);
		}
	}
}
