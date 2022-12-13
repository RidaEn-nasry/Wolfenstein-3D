/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darr_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:22:43 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/13 20:19:19 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  add a new element to a doubly linked list
 * @note   
 * @param  **arr: 
 * @param  *content: 
 * @retval modified array
 */

char	**ft_2darr_add(char **arr, char *content)
{
	size_t	len;

	len = ft_2darr_len((const char **)arr);
	arr = (char **)ft_2darr_realloc((void **)arr, len + 1);
	arr[len] = ft_strdup(content);
	return (arr);
}
