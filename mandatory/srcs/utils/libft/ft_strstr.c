/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:57:48 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/04/21 22:46:16 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	ft_strstr(const char *heystack, const char *needle) 
	locate the first occurrence of 
	the null-terminated string needle in the string heystack.
	
	it returns a pointer to the located string, or NULL if the string is not found.
*/

#include "libft.h"

char	*ft_strstr(const char *heystack, const char *needle)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)heystack);
	while (heystack[i] != '\0')
	{
		if (heystack[i] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&heystack[i - j + 1]);
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
		i++;
	}
	return (0);
}
