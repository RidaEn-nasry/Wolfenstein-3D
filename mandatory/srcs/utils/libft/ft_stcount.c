/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stcount.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:04:41 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:53:36 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_stcount count how many c are in the beginning and the tail of string s 
	@param s the string to count c in
	@param c the c to count
	@return an array of 2 ints. arr[0] is the number of c in the beginning 
		of s and arr[1] is the number of c in the tail of s.
*/
#include "libft.h"

int	*ft_stcount(const char *s, char c)
{
	int	i;
	int	*arr;
	int	count;

	count = 0;
	arr = malloc(sizeof(int) * 2);
	i = 0;
	while (s[i] && (s[i] == c || s[i] == ' '))
	{
		if (s[i] == c)
			count++;
		i++;
	}
	arr[0] = count;
	count = 0;
	i = ft_strlen(s) - 1;
	while (i >= 0 && (s[i] == c || s[i] == ' '))
	{
		if (s[i] == c)
			count++;
		i--;
	}
	arr[1] = count;
	return (arr);
}
