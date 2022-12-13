/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:23:44 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/11/15 14:41:13 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* copying memory area src to dst,
**if dst and src are the same or n == 0 return dest*/
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == src || !n)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i = i + 1;
	}
	return (dst);
}
