/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 07:45:56 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/11/15 14:39:29 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memcmp() function compares byte string s1 against byte string s2.
** Both strings are assumed to be n bytes long.
** The memcmp() function returns zero if the two strings are identical,
** otherwise returns the difference between the first two differing bytes.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == s2 || n == 0)
		return (0);
	while (i < n)
	{
		if (((unsigned const char *)s1)[i] != ((unsigned const char *)s2)[i])
		{
			return (((unsigned const char *)s1)[i] - \
				((unsigned const char *)s2)[i]);
		}
		i = i + 1;
	}
	return (0);
}
