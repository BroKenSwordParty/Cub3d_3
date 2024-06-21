/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 01:51:15 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/21 23:35:11 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	my_mlx_pixel_put(t_cubed *s, int x, int y, int color)
{
	char	*dst;

	dst = s->mlx_s.addr + (y * s->mlx_s.line_length + x * (s->mlx_s.bits_per_pixel / 8));

	//printf("TESTEO DE VALORES:\n\ny= %d\nline_length= %d\nbits_per_pixel= %d\nx: %d\n\n", y, s->mlx_s.line_length, s->mlx_s.bits_per_pixel, x);
	
	*(unsigned int *)dst = color; //AQUI x2
} 
// He puesto esto y se queda en bucle intentando pintar
/*void my_mlx_pixel_put(t_cubed *s, int x, int y, int color) 
{
    char *dst;
    // Verifica que las coordenadas estén dentro de los límites de la imagen
    if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGTH) {
        printf("Error: Coordenadas fuera de los límites (%d, %d)\n", x, y);
        return;
    }
    // Calcula la posición en la memoria del pixel (x, y)
    dst = s->mlx_s.addr + (y * s->mlx_s.line_length + x * (s->mlx_s.bits_per_pixel / 8));
    // Asegúrate de que dst no es NULL
    if (dst == NULL) {
        printf("Error: Dirección de memoria no válida\n");
        return;
    }
    // Escribe el color en la posición calculada
    color = *(unsigned int *)dst; 
}*/

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