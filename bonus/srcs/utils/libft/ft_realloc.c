/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:37:56 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:54:48 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ft_realloc expand the size of the memory allocated to the pointer p
   @param p the pointer to expand
   @param size the new size of the memory
   @return the new pointer to the memory
*/

void	*ft_realloc(void *p, size_t size)
{
	void	*new;

	exitif(!p, "p cannot be NULL");
	exitif(!size, "size cannot be 0");
	new = malloc(size);
	exitif(!new, "allocation failed");
	ft_memcpy(new, p, size);
	free(p);
	return (new);
}
