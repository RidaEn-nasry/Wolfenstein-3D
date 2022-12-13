/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:23:02 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/11/15 14:43:23 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* fill a memory area (string) with a byte value */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	ch;
	char			*rslt;

	ch = c;
	i = 0;
	rslt = b;
	while (i < len)
	{
		rslt[i] = ch;
		i = i + 1;
	}
	return (b);
}
