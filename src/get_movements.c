/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_momements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:10:36 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/18 18:13:00 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
void	player_a(t_cubed *s)
{
	double	moved_x;
	double	moved_y;

	moved_x = s->player.pos_x + s->player.dir_y * MOVE_SPEED;
	moved_y = s->player.pos_y - s->player.dir_x * MOVE_SPEED;
	if (s->imgs.map[(int)moved_y][(int)(s->player.pos_x)] != '1')
		s->player.pos_y = moved_y;
	if (s->imgs.map[(int)s->player.pos_y][(int)moved_x] != '1')
		s->player.pos_x = moved_x;
	s->player.x = (s->player.pos_x);
	s->player.y = (s->player.pos_y);
	change_value(s);
	printf("\e[1;1H\e[2J");
}

void	player_d(t_cubed *s)
{
	double	moved_x;
	double	moved_y;

	moved_x = s->player.pos_x - s->player.dir_y * MOVE_SPEED;
	moved_y = s->player.pos_y + s->player.dir_x * MOVE_SPEED;
	if (s->imgs.map[(int)moved_y][(int)(s->player.pos_x)] != '1')
		s->player.pos_y = moved_y;
	if (s->imgs.map[(int)(s->player.pos_y)][(int)moved_x] != '1')
		s->player.pos_x = moved_x;
	s->player.x = (s->player.pos_x);
	s->player.y = (s->player.pos_y);
	change_value(s);
	printf("\e[1;1H\e[2J");
}

void	player_w(t_cubed *s)
{
	double	moved_x;
	double	moved_y;

	moved_x = s->player.pos_x + s->player.dir_x * MOVE_SPEED;
	moved_y = s->player.pos_y + s->player.dir_y * MOVE_SPEED;
	if (s->imgs.map[(int)moved_y][(int)s->player.pos_x] != '1')
		s->player.pos_y = moved_y;
	if (s->imgs.map[(int)s->player.pos_y][(int)moved_x] != '1')
		s->player.pos_x = moved_x;
	s->player.x = (s->player.pos_x);
	s->player.y = (s->player.pos_y);
	change_value(s);
	printf("\e[1;1H\e[2J");
}

void	player_s(t_cubed *s)
{
	double	moved_x;
	double	moved_y;

	moved_x = s->player.pos_x - s->player.dir_x * MOVE_SPEED;
	moved_y = s->player.pos_y - s->player.dir_y * MOVE_SPEED;
	if (s->imgs.map[(int)moved_y][(int)(s->player.pos_x)] != '1')
		s->player.pos_y = moved_y;
	if (s->imgs.map[(int)(s->player.pos_y)][(int)moved_x] != '1')
		s->player.pos_x = moved_x;
	s->player.x = (s->player.pos_x);
	s->player.y = (s->player.pos_y);
	change_value(s);
	printf("\e[1;1H\e[2J");
}