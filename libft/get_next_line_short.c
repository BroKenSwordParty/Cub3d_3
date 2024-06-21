/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchamorr <jchamorr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 10:50:54 by jchamorr          #+#    #+#             */
/*   Updated: 2022/05/27 12:40:02 by jchamorr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *get_next_line_short(int fd)
{
    int 	i = 0;
    int 	rd = 0;
    char	c;
    char 	*buff = malloc(10000);

    while ((rd = read(fd, &c, 1)) > 0)
    {
        buff[i++] = c;
        if (c == '\n')
            break ;
    }
    if ((!buff[i - 1] && !rd) || rd == -1)
    {
        free(buff);
        return (NULL);
    }
    buff[i] =  '\0';
    return(buff);
}