/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 18:07:49 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/22 00:19:38 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include   "../inc/cub3d.h"

int	ft_esc(t_cubed *s)
{
	mlx_clear_window(s->mx, s->mw);
	mlx_destroy_window(s->mx, s->mw);
	free_double_char(s->imgs.map);
	free (s->tex[0].img);
	free (s->tex[1].img);
	free (s->tex[2].img);
	free (s->tex[3].img);
	exit(EXIT_SUCCESS);
}

int	ft_input(int keycode, t_cubed *s)
{
	if (keycode == 53)
		ft_esc(s);
	if (keycode == 13)
		player_w(s);
	if (keycode == 0)
		player_a(s);
	if (keycode == 1)
		player_s(s);
	if (keycode == 2)
		player_d(s);
	if (keycode == 123)
		cam_left(s);
	if (keycode == 124)
		cam_right(s);
	return (0);
}

int	raycast(t_cubed *s)
{
	t_ray	ray;

	ray.x = 0;
	while (ray.x < WIDTH)
	{
		raycast_init(s, &ray);
		raycast_dir(s, &ray);
		raycast_hit(s, &ray);
		raycast_draw_pos(s, &ray);
		texturing_calculations(s, &ray);
		
		ray.x++;
	}
	mlx_put_image_to_window(s->mx, s->mw, s->mlx_s.img, 0, 0);
	mlx_clear_window(s->mx, s->mw);
	return (0);
}

void	init_window(t_cubed *s)
{
	s->mx = mlx_init();
    s->mw = mlx_new_window(s->mx, WIDTH, HEIGTH, NAME);
    s->mlx_s.img = mlx_new_image(s->mx, WIDTH, HEIGTH);
    s->mlx_s.addr = mlx_get_data_addr(s->mlx_s.img, &s->mlx_s.bits_per_pixel,&s->mlx_s.line_length, &s->mlx_s.endian);
   	printf("bits_per_pixel en init window: %d\n", s->mlx_s.bits_per_pixel);
	printf("line_length en init window: %d\n", s->mlx_s.line_length);

    mlx_hook(s->mw, 2, 1L << 0, ft_input, s);
    mlx_hook(s->mw, 17, 1L << 17, ft_esc, s);
    mlx_loop_hook(s->mx, raycast, s);
    mlx_loop(s->mx);
    //mlx_clear_window(s->mx, s->mw);
    //mlx_destroy_window((*s)->mx, (*s)->mw);
}