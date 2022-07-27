/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_2darr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:49:34 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:51:28 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief store a file's content in a 2d array and return it
 * @param file path to file
 * @return char** 2d array of file's content or NULL if error
 */

char	**ft_file_to_2darr(char *file)
{
	char	**arr;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if (!file)
		return (NULL);
	arr = malloc(sizeof(char *) * (ft_filelcount(file) + 1));
	if (!arr)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		arr[i] = line;
		line = get_next_line(fd);
		i++;
	}
	arr[i] = NULL;
	close(fd);
	return (arr);
}
