/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:11:05 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/20 20:55:35 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	raycast_init(t_cubed *s, t_ray *ray)
{
	ray->camera_x = 2 * ray->x / (double)s->width - 1;
	ray->raydir_x = s->player.dir_x + s->player.plane_x * ray->camera_x;
	ray->raydir_y = s->player.dir_y + s->player.plane_y * ray->camera_x;
	ray->map_x = (int)s->player.pos_x;
	ray->map_y = (int)s->player.pos_y;
	if (ray->raydir_x == 0)
		ray->delta_dist_x = exp(30);
	else
		ray->delta_dist_x = fabs(1.0 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->delta_dist_y = exp(30);
	else
		ray->delta_dist_y = fabs(1.0 / ray->raydir_y);
}

void	raycast_dir(t_cubed *s, t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (s->player.pos_x - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - s->player.pos_x)
			* ray->delta_dist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (s->player.pos_y - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - s->player.pos_y)
			* ray->delta_dist_y;
	}
}

void	raycast_hit(t_cubed *s, t_ray *ray)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (s->imgs.map[ray->map_y][ray->map_x] == '1') // map en struct principal??
				ray->hit = 1;
	}
}

void	raycast_draw_pos(t_cubed *s, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	ray->h = s->height;
	ray->line_height = (int)(s->height / ray->perp_wall_dist);
	if (ray->perp_wall_dist <= 0)
		ray->line_height = s->height;
	ray->draw_start = -ray->line_height / 2 + s->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + s->height / 2;
	if (ray->draw_end >= s->height)
		ray->draw_end = s->height - 1;
}

void	texturing_calculations(t_cubed *s, t_ray *ray)
{
	double		wall_x;
	double		step;
	double		tex_pos;

	get_texture_id(ray);
	if (ray->side == 0)
		wall_x = s->player.pos_y + ray->perp_wall_dist * ray->raydir_y;
	else
		wall_x = s->player.pos_x + ray->perp_wall_dist * ray->raydir_x;
	wall_x -= floor((wall_x));
	ray->tex_x = (int)(wall_x * (double)s->tex[ray->tex].w);
	if (ray->side == 0 && ray->raydir_x > 0)
		ray->tex_x = s->tex[ray->tex].w - ray->tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		ray->tex_x = s->tex[ray->tex].w - ray->tex_x - 1;
	step = 1.0 * s->tex[ray->tex].h / ray->line_height;
	tex_pos = (ray->draw_start - ray->h / 2 + ray->line_height / 2) * step;
	printf("addr1: %p\n", s->mlx_s.addr);
	print_texture(s, *ray, tex_pos, step);
}