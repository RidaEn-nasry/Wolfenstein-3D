/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filecpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:03:36 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:57:32 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief  duplicating an already existing file into a new file
 * @note   if cpytofile does not exist, it will be created
 * @param  *cpyfromfile: the file to be copied
 * @param  *cpytofile: the file to be copied to
 * @param mode: the mode of the file to be copied to
 * @retval int: 0 in success, 1 in failure
 */

int	ft_filecpy(char *cpyfromfile, char *cpytofile, int mode)
{
	int		fd;
	int		fdcpy;
	size_t	rd;
	char	buff;

	fd = open(cpyfromfile, O_RDONLY);
	if (fd == -1)
		return (-1);
	fdcpy = open(cpytofile, mode, 0644);
	if (fdcpy == -1 || !ft_validfname(cpytofile))
		return (-1);
	rd = read(fd, &buff, 1);
	while (rd > 0)
	{
		write(fdcpy, &buff, 1);
		rd = read(fd, &buff, 1);
	}
	close(fd);
	close(fdcpy);
	return (0);
}
