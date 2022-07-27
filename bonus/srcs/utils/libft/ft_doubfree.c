/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:29:57 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/13 20:17:07 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
	ft_doubfree:
		@description:
			- free a pointer to pointer and set it to NULL
		@params:
			- void **ptr: pointer to pointer to free
			- size_t size if size 0 free from 0 to size,
			 else free from size to 0.
		@return:
			- void 
		@note:
			- useful to free a list of pointers
*/

void	ft_doubfree(void **ptr, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_2darr_len((const char **)ptr);
	i = 0;
	if (!size)
	{
		while (i < len)
		{
			ft_sfree(ptr[i]);
			i = i + 1;
		}
	}
	else
	{
		while (i < size)
		{
			ft_sfree(ptr[i]);
			i++;
		}
	}
	free(ptr);
}
