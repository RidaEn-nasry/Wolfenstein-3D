/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 15:57:00 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:54:28 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
    ft_safeFree:
        @description:
            - free a pointer if it is not NULL 
        @param:
            - void *ptr: pointer to free
        @return:
            - void
*/

#include "libft.h"

void	ft_sfree(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}
