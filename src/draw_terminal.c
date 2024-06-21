/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_terminal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:11:45 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/18 17:11:48 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	position_values(t_cubed *s, int i, int j)
{
	if (s->player.y == i && s->player.x == j)
		printf("🎮");
	else if (s->imgs.map[i][j] == ' ')
		printf("  ");
	else if (s->imgs.map[i][j] == '1')
		printf("\xF0\x9F\x8C\xB4");
	else if (s->imgs.map[i][j] == '0')
		printf("🟦");
}

void	print_data(t_cubed *s)
{
	printf("\n---------\n");
	printf("PLAYER \npos = (%f, %f) -- (%d, %d)\n",
		s->player.pos_x, s->player.pos_y,
		s->player.x, s->player.y);
	printf("dir = (%f, %f)\nplane = (%f, %f)\n",
		s->player.dir_x, s->player.dir_y,
		s->player.plane_x, s->player.plane_y);
}

void	change_value(t_cubed *s)
{
	int	i;
	int	j;

	i = -1;
	while (s->imgs.map[++i])
	{
		j = -1;
		while (++j < s->width)
		{
			if (!s->imgs.map[i][j])
				break ;
			position_values(s, i, j);
		}
		printf("\n");
	}
	print_data(s);
}