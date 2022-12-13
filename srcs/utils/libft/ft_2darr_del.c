/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2darr_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:16:17 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/13 20:18:32 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	@description:
		- delete a range of char * from an array of char *
	@param:
		- char **arr: array of char *
		- int start: index of the first char * to delete
		- int end: index of the last char * to delete
	@return:
		- char **: the new array of char *
		- NULL: if the start or end index is out of range
		- NULL: if the start index is greater than the end index
	@note:
		- the start index is included in the range
		- the end index is excluded from the range
	@IMPORTANT:
		- the index of array char * will be changed, e.i if you delete the first
			char * of the array, the index of the array will be decremented by 1 for each.
	@example:
		- char **arr = {"hello", "world", "!"};
		- ft_doubdel(arr, 0, 1);
		- arr = {"world", "!"};
*/

#include "libft.h"

bool	check_null(char **array, size_t start, size_t end, size_t *len)
{
	if (!array || !*array)
		return (false);
	if (start > end)
		return (false);
	*len = ft_2darr_len((const char **)array);
	if (start >= *len || end > *len)
		return (false);
	return (true);
}

char	**ft_2darr_del(char **array, size_t start, size_t end)
{
	size_t	len;
	char	**new_array;
	size_t	i;

	i = 0;
	if (!check_null(array, start, end, &len))
		return (NULL);
	new_array = malloc(sizeof(char *) * (len - (end - start) + 1));
	if (!new_array)
		return (NULL);
	while (i < start)
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	i = end;
	while (i < len)
	{
		new_array[i - (end - start)] = ft_strdup(array[i]);
		i++;
	}
	new_array[i - (end - start)] = NULL;
	ft_doubfree((void **)array, 0);
	return (new_array);
}
