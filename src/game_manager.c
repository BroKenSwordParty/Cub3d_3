/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:07:49 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/23 14:46:32 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_esc(t_cubed *s)
{
	mlx_destroy_image(s->mx, s->mlx_s.img);
	mlx_clear_window(s->mx, s->mw);
	mlx_destroy_window(s->mx, s->mw);
	ft_free_exit(s, 0);
	return (1);
}

int	ft_input(int keycode, t_cubed *s)
{
	if (keycode == 65307)
		ft_esc(s);
	if (keycode == 119)
		player_w(s);
	if (keycode == 97)
		player_a(s);
	if (keycode == 115)
		player_s(s);
	if (keycode == 100)
		player_d(s);
	if (keycode == 65361)
		cam_left(s);
	if (keycode == 65363)
		cam_right(s);
	return (0);
}

int	raycast(t_cubed *s)
{
	t_ray	ray;

	ray.x = 0;
	mlx_clear_window(s->mx, s->mw);
	while (ray.x < s->width)
	{
		raycast_init(s, &ray);
		raycast_dir(s, &ray);
		raycast_hit(s, &ray);
		raycast_draw_pos(s, &ray);
		texturing_calculations(s, &ray);
		ray.x++;
	}
	mlx_put_image_to_window(s->mx, s->mw, s->mlx_s.img, 0, 0);
	return (0);
}

void	init_window(t_cubed *s)
{
	s->mx = mlx_init();
	s->width = WIDTH;
	s->height = HEIGTH;
	s->mlx_s.img = mlx_new_image(s->mx, s->width, s->height);
	s->mlx_s.addr = mlx_get_data_addr(s->mlx_s.img, &s->mlx_s.bits_per_pixel,
			&s->mlx_s.line_length, &s->mlx_s.endian);
	s->mw = mlx_new_window(s->mx, s->width, s->height, NAME);
	validate_file(s);
	if (validate_file(s) == 1)
	{
		mlx_destroy_image(s->mx, s->mlx_s.img);
		mlx_clear_window(s->mx, s->mw);
		mlx_destroy_window(s->mx, s->mw);
		ft_free_exit(s, 1);
	}
	mlx_hook(s->mw, 2, 1L << 0, ft_input, s);
	mlx_hook(s->mw, 17, 1L << 17, ft_esc, s);
	mlx_loop_hook(s->mx, raycast, s);
	mlx_loop(s->mx);
	mlx_clear_window(s->mx, s->mw);
	mlx_destroy_window(s->mx, s->mw);
}
