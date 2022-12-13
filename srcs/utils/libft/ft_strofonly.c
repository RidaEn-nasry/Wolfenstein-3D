/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strofonly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:13:49 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:51:40 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief str contains only chars from charset * 
 * @param str string to check
 * @param charset charset to check against 
 * @return true if str contains only chars from charset * false otherwise
 */

bool	ft_strofonly(char *str, char *charset)
{
	int		i;
	size_t	j;

	i = 0;
	if (!str || !charset)
		return (false);
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
				break ;
			if (j == ft_strlen(charset) - 1)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
