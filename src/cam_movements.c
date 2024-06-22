/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_movements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:54:56 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/22 21:57:51 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	cam_left(t_cubed *s)
{
	s->player.old_dir_x = s->player.dir_x;
	s->player.dir_x = s->player.dir_x
		* cos(-ROT_SPEED) - s->player.dir_y * sin(-ROT_SPEED);
	s->player.dir_y = s->player.old_dir_x
		* sin(-ROT_SPEED) + s->player.dir_y * cos(-ROT_SPEED);
	s->player.old_plane_x = s->player.plane_x;
	s->player.plane_x = s->player.plane_x
		* cos(-ROT_SPEED) - s->player.plane_y * sin(-ROT_SPEED);
	s->player.plane_y = s->player.old_plane_x
		* sin(-ROT_SPEED) + s->player.plane_y * cos(-ROT_SPEED);
}

void	cam_right(t_cubed *s)
{
	s->player.old_dir_x = s->player.dir_x;
	s->player.dir_x = s->player.dir_x
		* cos(ROT_SPEED) - s->player.dir_y * sin(ROT_SPEED);
	s->player.dir_y = s->player.old_dir_x
		* sin(ROT_SPEED) + s->player.dir_y * cos(ROT_SPEED);
	s->player.old_plane_x = s->player.plane_x;
	s->player.plane_x = s->player.plane_x
		* cos(ROT_SPEED) - s->player.plane_y * sin(ROT_SPEED);
	s->player.plane_y = s->player.old_plane_x
		* sin(ROT_SPEED) + s->player.plane_y * cos(ROT_SPEED);
}
