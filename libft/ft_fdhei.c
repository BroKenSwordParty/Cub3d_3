/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strhei.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:52:41 by jchamorr          #+#    #+#             */
/*   Updated: 2022/06/06 11:05:48 by jchamorr         ###   ########.fr       */
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