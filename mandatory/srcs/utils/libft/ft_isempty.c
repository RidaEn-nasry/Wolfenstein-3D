/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:49:15 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:37:20 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief check is line is empty 
 * @howto: check is line contains only spaces and/or tabs and/or newlines
 * @param str line to check 
 * @return true 
 * @return false 
 */

bool	ft_isempty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}
