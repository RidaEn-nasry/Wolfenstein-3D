/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:59:18 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/06/05 12:57:30 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	@description:   
		- this function returns the value of the environment variable
		- if the variable is not found, it returns NULL
	@param:
		- char *name: the name of the variable
	@return:
		- char *: the value of the variable
*/

#include "libft.h"

char	*ft_getenv(char **env, char *name)
{
	size_t	i;
	char	*env_name;
	size_t	len;

	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		env_name = ft_substr(env[i], 0, ft_strchr(env[i], '=') - env[i]);
		if (ft_strncmp(env_name, name, len) == 0)
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}
