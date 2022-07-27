/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_envname.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 11:48:29 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:48:27 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    @description:
        - check if the given string is a valid env variable name
        - valid env variable name must start with a letter
		and can contain onlt letters, numbers and underscores
    @param:
        - char *env_name: the string to check
    @return:
        - bool: true if the string is a valid env variable name, false otherwise
    @complexity:
        - O(n)
*/

#include "libft.h"

bool	ft_valid_envname(char *env_name)
{
	size_t	i;

	if (!env_name)
		return (false);
	if (!ft_isalpha(env_name[0]))
		return (false);
	i = 0;
	while (env_name[i])
	{
		if (!ft_isalnum(env_name[i]) && env_name[i] != '_')
			return (false);
		i++;
	}
	return (true);
}
