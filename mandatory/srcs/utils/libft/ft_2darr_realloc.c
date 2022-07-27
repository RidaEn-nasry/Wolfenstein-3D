/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darr_realloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:14:23 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/13 20:02:25 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

	ft_2darr_realloc:
		@description:
			- reallocate a pointer to pointer 
		@params:
			- void **ptr: pointer to pointer to reallocate
			- int size: size to reallocate
		@return:
			- newly allocated pointer to pointer
			- NULL if failed
*/

#include "libft.h"

void	**ft_2darr_realloc(void **ptr, size_t size)
{
	void	**new;
	size_t	i;

	i = 0;
	if (!ptr)
		return (NULL);
	if (!size)
		return (ptr);
	new = malloc(sizeof(void *) * size + 1);
	if (!new)
		return (NULL);
	while (ptr[i])
	{
		new[i] = ft_strdup(ptr[i]);
		if (!new[i])
			ft_doubfree(new, i);
		i++;
	}
	new[size] = NULL;
	ft_doubfree(ptr, 0);
	return (new);
}
