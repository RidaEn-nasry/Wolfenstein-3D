/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 01:14:14 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 23:10:21 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>
#include <parser.h>

bool	check_plyr(char **map, int i, int j)
{
	if (!is_plyr(map[i][j]))
		return (true);
	else if (is_plyr(map[i][j]))
	{
		if ((ft_isspace(map[i][j + 1]) || ft_isspace(map[i][j - 1])) || \
			(ft_isspace(map[i + 1][j]) || ft_isspace(map[i - 1][j])))
			return (false);
	}
	return (true);
}

void	free_and_gnl(char **line, int fd)
{
	free(*line);
	*line = get_next_line(fd);
}

char	*check_line_get_mp(char *line)
{
	char	*trim;
	size_t	len;
	int		count;
	int		i;

	count = 0;
	trim = line;
	len = ft_strlen(trim);
	i = 0;
	if (trim[len - 1] == '\n')
	{
		trim[len - 1] = '\0';
		count += 1;
	}
	while (trim[i] != '\0')
	{
		if (ft_isspace(trim[i]))
		{
			trim[i] = '1';
		}
		i++;
	}
	return (trim);
}
