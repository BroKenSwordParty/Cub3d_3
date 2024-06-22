/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:53:50 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/22 22:20:31 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

unsigned int	get_mlx_pixel_color(t_mlx *mlx_s, int x, int y)
{
	char			*dst;
	int				offset;
	unsigned int	color;

	offset = (y * mlx_s->line_length + x * (mlx_s->bits_per_pixel / 8));
	dst = mlx_s->addr + offset;
	color = *(unsigned int *)dst;
	return (color);
}

void	my_mlx_draw_column(t_cubed *s, t_ray ray, t_mlx texture)
{
	my_mlx_pixel_put(s, ray.x, ray.y,
		get_mlx_pixel_color(&texture, ray.tex_x, ray.tex_y));
}

void	get_texture_id(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->raydir_x > 0)
			ray->tex = 3;
		else
			ray->tex = 2;
	}
	else
	{
		if (ray->raydir_y > 0)
			ray->tex = 1;
		else
			ray->tex = 0;
	}
}

void	print_texture(t_cubed *s, t_ray ray, double tex_pos, double step)
{
	ray.y = 0;
	color_rgb_ceiling(s);
	while (ray.y < ray.draw_start)
		my_mlx_pixel_put(s, ray.x, ray.y++, s->imgs.ceiling);
	ray.y = ray.draw_start;
	while (ray.y < ray.draw_end)
	{
		ray.tex_y = (int)tex_pos & (s->tex[ray.tex].h - 1);
		tex_pos += step;
		my_mlx_draw_column(s, ray, s->tex[ray.tex]);
		ray.y++ ;
	}
	color_rgb_floor(s);
	while (ray.y < s->height)
		my_mlx_pixel_put(s, ray.x, ray.y++, s->imgs.floor);
}
