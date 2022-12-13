/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darr_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 19:39:05 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/13 20:17:41 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	@description:
		- concatenates char ** into a new string using a delimiter
	@param:
		- char **str: string to concatenate
		- char *delim: delimiter
	
	@return:
		- char *: the concatenated string
		- if str is NULL, return NULL
		- if str is empty, return an empty string
	@note:
		- if delim is NULL, there should be no delimiter
*/

#include "libft.h"

char	*ft_2darr_to_str(char **str, char *delim)
{
	size_t	i;
	char	*ret;
	size_t	len;

	i = 0;
	if (!str)
		return (NULL);
	if (!str[0])
		return (ft_strdup(""));
	ret = ft_strdup("");
	len = ft_2darr_len((const char **)str);
	while (str[i])
	{
		ret = ft_strjoin(ret, str[i]);
		if (delim && i < len - 1)
			ret = ft_strjoin(ret, delim);
		if (!ret)
			ft_doubfree((void **)str, i);
		i++;
	}
	ft_doubfree((void **)str, 0);
	return (ret);
}
