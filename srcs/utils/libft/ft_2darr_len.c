/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darr_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 09:29:54 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 19:32:51 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_2darr_len(const char **)
	* 
	* @description: this function computes the length of the double pointer. 
	* @param const char **double: pointer to a pointer to a string
	* @return: the length of the string
*/

#include "libft.h"

size_t	ft_2darr_len(char const **doub)
{
	size_t	i;

	i = 0;
	while (doub[i])
		i++;
	return (i);
}
