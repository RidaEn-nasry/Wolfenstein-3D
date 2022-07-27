/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 01:31:15 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/11/26 02:44:36 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	index_line(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (p[i])
	{
		if (p[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static void	get_rest(char **save, char **line, ssize_t end, char **tmp)
{
	if (end == 0 && !ft_strchr(*save, '\n'))
	{
		*line = ft_strdup(*save);
		*save = 0;
	}
	else
	{
		*line = ft_substr(*save, 0, index_line(*save, '\n') + 1);
		*save = ft_strdup(*save + index_line(*save, '\n') + 1);
	}
	free(*tmp);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
}

static void	get_line(int fd, char **save, char *buff, char **line)
{
	ssize_t	end;
	char	*tmp;

	end = 1;
	buff[0] = '\0';
	while (end != 0 && (!ft_strchr(buff, '\n')))
	{
		end = read(fd, buff, BUFFER_SIZE);
		buff[end] = '\0';
		tmp = *save;
		*save = ft_strjoin(tmp, buff);
		free(tmp);
	}
	free(buff);
	tmp = *save;
	get_rest(save, line, end, &tmp);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*buff;
	char		*line;

	buff = NULL;
	if (read(fd, buff, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!save[fd])
		save[fd] = ft_strdup("");
	get_line(fd, &save[fd], buff, &line);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd1 = open("foo.txt", O_RDONLY);
// 	int fd2 = open("bar.txt", O_RDONLY);
// 	for (int i = 0; i < 2; i++)
// 	{
// 		printf("%s", get_next_line(fd1));
// 		printf("%s", get_next_line(fd2));
// 	}	
// 	return 0;
// }
