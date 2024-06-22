/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 01:51:15 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/22 22:19:42 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_cubed *s, int x, int y, int color)
{
	char	*dst;

	dst = s->mlx_s.addr + (y * s->mlx_s.line_length + x
			* (s->mlx_s.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_column_color(t_cubed *s, t_ray ray, int color)
{
	int	y;

	y = 0;
	while (y < ray.draw_start)
	{
		my_mlx_pixel_put(s, ray.x, y, s->imgs.ceiling);
		y++;
	}
	y = ray.draw_start;
	while (y <= ray.draw_end)
	{
		my_mlx_pixel_put(s, ray.x, y, color);
		y++;
	}
	if (ray.draw_end + 1 > s->height)
		return ;
	y = ray.draw_end + 1;
	while (y < s->height)
	{
		my_mlx_pixel_put(s, ray.x, y, s->imgs.floor);
		y++;
	}
}

void	print_map_ew(t_cubed *s, t_ray ray)
{
	if (s->imgs.map[s->player.y][s->player.x] == 'E')
	{
		if (ray.side == 1)
		{
			if (ray.x <= s->width / 2)
				my_mlx_column_color(s, ray, 0x00FF0000);
			else
				my_mlx_column_color(s, ray, 0x006F00FF);
		}
		else
			my_mlx_column_color(s, ray, 0x00D7D7A8);
	}
	else if (s->imgs.map[s->player.y][s->player.x] == 'W')
	{
		if (ray.side == 1)
		{
			if (ray.x >= s->width / 2)
				my_mlx_column_color(s, ray, 0x00FF0000);
			else
				my_mlx_column_color(s, ray, 0x006F00FF);
		}
		else
			my_mlx_column_color(s, ray, 0x002D2926);
	}
}

void	print_map_ns(t_cubed *s, t_ray ray)
{
	if (s->imgs.map[s->player.y][s->player.x] == 'N')
	{
		if (ray.side == 1)
			my_mlx_column_color(s, ray, 0x00FF0000);
		else
		{
			if (ray.x <= s->width / 2)
				my_mlx_column_color(s, ray, 0x002D2926);
			else
				my_mlx_column_color(s, ray, 0x00D7D7A8);
		}
	}
	else if (s->imgs.map[s->player.y][s->player.x] == 'S')
	{
		if (ray.side == 1)
			my_mlx_column_color(s, ray, 0x006F00FF);
		else
		{
			if (ray.x >= s->width / 2)
				my_mlx_column_color(s, ray, 0x002D2926);
			else
				my_mlx_column_color(s, ray, 0x00D7D7A8);
		}
	}
}

void	print_map(t_cubed *s, t_ray ray)
{
	char	c;

	c = s->imgs.map[s->player.y][s->player.x];
	if (c == 'N' || c == 'S')
		print_map_ns(s, ray);
	else if (c == 'E' || c == 'W')
		print_map_ew(s, ray);
}
