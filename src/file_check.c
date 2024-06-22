/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 21:26:54 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/22 22:26:54 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	validate_file(t_cubed *s)
{
	if (check_textures(&s->imgs) == 1)
		return (printf(F_ERR), 1);
	if (check_colours(&s->imgs) == 1)
		return (printf(C_ERR), 1);
	s->tex[0].img = mlx_xpm_file_to_image(s->mx, s->imgs.no,
			&s->tex[0].w, &s->tex[0].h);
	s->tex[1].img = mlx_xpm_file_to_image(s->mx, s->imgs.so,
			&s->tex[1].w, &s->tex[1].h);
	s->tex[2].img = mlx_xpm_file_to_image(s->mx, s->imgs.ea,
			&s->tex[2].w, &s->tex[2].h);
	s->tex[3].img = mlx_xpm_file_to_image(s->mx, s->imgs.we,
			&s->tex[3].w, &s->tex[3].h);
	s->tex[0].addr = mlx_get_data_addr(s->tex[0].img, &s->tex[0].bits_per_pixel,
			&s->tex[0].line_length, &s->tex[0].endian);
	s->tex[1].addr = mlx_get_data_addr(s->tex[1].img, &s->tex[1].bits_per_pixel,
			&s->tex[1].line_length, &s->tex[1].endian);
	s->tex[2].addr = mlx_get_data_addr(s->tex[2].img, &s->tex[2].bits_per_pixel,
			&s->tex[2].line_length, &s->tex[2].endian);
	s->tex[3].addr = mlx_get_data_addr(s->tex[3].img, &s->tex[3].bits_per_pixel,
			&s->tex[3].line_length, &s->tex[3].endian);
	return (0);
}

int	check_ext(t_imgs *imgs)
{
	if (!(imgs->no || ft_strcmp(ft_strrchr(imgs->no, '.'), ".xpm") == 0))
		return (1);
	if (!(imgs->so || ft_strcmp(ft_strrchr(imgs->so, '.'), ".xpm") == 0))
		return (1);
	if (!(imgs->ea || ft_strcmp(ft_strrchr(imgs->ea, '.'), ".xpm") == 0))
		return (1);
	if (!(imgs->we || ft_strcmp(ft_strrchr(imgs->we, '.'), ".xpm") == 0))
		return (1);
	return (0);
}

int	check_textures(t_imgs *imgs)
{
	if (check_ext(imgs))
		return (1);
	if (ft_strchr(imgs->no, ' ') != NULL || ft_strchr(imgs->so, ' ') != NULL
		|| ft_strchr(imgs->ea, ' ') != NULL || ft_strchr(imgs->we, ' ') != NULL)
		return (1);
	if (try_open(imgs))
		return (1);
	return (0);
}

int	check_colours(t_imgs *imgs)
{
	if (ft_atoi(imgs->f[0]) < 0 || ft_atoi(imgs->f[1]) < 0
		|| ft_atoi(imgs->f[2]) < 0)
		return (1);
	if (ft_atoi(imgs->f[0]) > 255 || ft_atoi(imgs->f[1]) > 255
		|| ft_atoi(imgs->f[2]) > 255)
		return (1);
	if (ft_atoi(imgs->c[0]) < 0 || ft_atoi(imgs->c[1]) < 0
		|| ft_atoi(imgs->c[2]) < 0)
		return (1);
	if (ft_atoi(imgs->c[0]) > 255 || ft_atoi(imgs->c[1]) > 255
		|| ft_atoi(imgs->c[2]) > 255)
		return (1);
	return (0);
}
