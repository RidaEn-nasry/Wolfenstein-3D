/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 15:34:54 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:37:33 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief  check is a char is a space
 * @note   
 * @param  c: 
 * @retval 1 if it is, 0 if not
 */

#include "libft.h"

bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
