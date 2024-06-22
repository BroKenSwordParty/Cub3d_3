/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 19:47:12 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/23 00:27:00 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*ft_strchr_array(char **array)
{
	int		i;
	int		j;
	int		count;
	int		c[2];

	i = -1;
	count = 0;
	while (array[++i])
	{
		j = 0;
		while (array[i][j] != '\0')
		{
			if (array[i][j] == 'N' || array[i][j] == 'S' ||
				array[i][j] == 'E' || array[i][j] == 'W')
			{
				count++;
				c[0] = i;
				c[1] = j;
			}
			j++;
		}
	}
	if (count == 1)
		return (&array[c[0]][c[1]]);
	return (0);
}

void	color_rgb_ceiling(t_cubed *s)
{
	int	rgb_c;
	int	r;
	int	g;
	int	b;

	r = ft_atoi(s->imgs.c[0]);
	g = ft_atoi(s->imgs.c[1]);
	b = ft_atoi(s->imgs.c[2]);
	rgb_c = r << 16 | g << 8 | b;
	s->imgs.ceiling = rgb_c;
}

void	color_rgb_floor(t_cubed *s)
{
	int	rgb_f;
	int	r;
	int	g;
	int	b;

	r = ft_atoi(s->imgs.f[0]);
	g = ft_atoi(s->imgs.f[1]);
	b = ft_atoi(s->imgs.f[2]);
	rgb_f = r << 16 | g << 8 | b;
	s->imgs.floor = rgb_f;
}
