/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envexist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:53:40 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:36:36 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    @descriotion: 
        - check if the env variable exist.
    @param:
        - char **env: the env variable.
        - char *name: the name of the env variable.
    @return:
        - bool : true if the env variable exist, false otherwise.
*/
#include "libft.h"

bool	ft_envexist(char **envs, char *env_name)
{
	size_t	i;

	i = 0;
	while (envs[i])
	{
		if (ft_strncmp(envs[i], env_name, ft_strlen(env_name)) == 0)
			return (true);
		i++;
	}
	return (false);
}
