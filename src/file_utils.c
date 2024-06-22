/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 20:22:06 by ghoyuelo          #+#    #+#             */
/*   Updated: 2024/06/22 23:27:23 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	try_open(t_imgs *imgs)
{
	int	fd;

	fd = open(imgs->no, O_RDONLY);
	if (fd == -1)
		return (printf(F_ERR), 1);
	close(fd);
	fd = open(imgs->so, O_RDONLY);
	if (fd == -1)
		return (printf(F_ERR), 1);
	close(fd);
	fd = open(imgs->ea, O_RDONLY);
	if (fd == -1)
		return (printf(F_ERR), 1);
	close(fd);
	fd = open(imgs->we, O_RDONLY);
	if (fd == -1)
		return (printf(F_ERR), 1);
	close(fd);
	return (0);
}

void	ft_doublefree(char **s)
{
	int	i;

	i = -1;
	if (!s || !*s)
		return ;
	while (s[++i])
	{
		printf("CHECK: %s\n", s[i]);
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

void	ft_free_exit(t_cubed *s, int i)
{
/* 	if (s->imgs.map)
		ft_doublefree(s->imgs.map); */
	if (s->file)
		ft_doublefree(s->file);
	if (s->imgs.no)
		free(s->imgs.no);
	if (s->imgs.so)
		free(s->imgs.so);
	if (s->imgs.ea)
		free(s->imgs.ea);
	if (s->imgs.we)
		free(s->imgs.we);
 	if (s->imgs.c)
		ft_doublefree(s->imgs.c);
	if (s->imgs.f)
		ft_doublefree(s->imgs.f);
	exit (i);
}
