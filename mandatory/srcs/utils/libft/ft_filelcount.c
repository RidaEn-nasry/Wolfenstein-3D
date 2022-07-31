/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filelcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:51:04 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 17:12:17 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @breif: count how many lines ina a file
 * @param: 
 * 	- char *file: path to file 
 * @return: on success read return >= 0 count or -1 in error
 **/
#include "libft.h"

size_t	ft_filelcount( char	*file)
{
	int		fd;
	size_t	count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	return (free(line), count);
}
