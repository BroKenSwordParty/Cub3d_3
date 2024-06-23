/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdhei.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyuelo <ghoyuelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:52:41 by jchamorr          #+#    #+#             */
/*   Updated: 2024/06/23 14:30:18 by ghoyuelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fdhei(int fd)
{
	int		i;
	char	*str;

	str = "1";
	i = 0;
	while (str)
	{
		str = get_next_line(fd);
		i++;
		free(str);
	}
	return (i);
}
