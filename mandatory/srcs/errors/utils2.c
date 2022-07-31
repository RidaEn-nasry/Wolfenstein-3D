/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 01:14:14 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 23:28:49 by ren-nasr         ###   ########.fr       */
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
			trim[i] = '1';
		i++;
	}
	return (trim);
}

char	**get_rgb(char *line, char **temp, t_map *map)
{
	char	**rgb;
	int		i;

	i = 0;
	while (line[i] != 'F' && line[i] != 'C')
		i++;
	i += 1;
	while (ft_isspace(line[i]))
		i++;
	temp = ft_split(&line[i], ',');
	exit_free_if(!temp, "Error:\n\tft_split failed", map, 1);
	rgb = ft_2darr_trim(temp, " ");
	exit_free_if(ft_2darr_len((const char **)rgb) != 3,
		"Error\n\tcolor format error", map, 1);
	return (rgb);
}

t_map	*map_init(t_map *map, char *map_file)
{
	map = init();
	map->map = ft_file_to_2darr(map_file);
	map->map = get_new_map(map->map);
	exit_free_if(!check_map(map->map), "Error:\n\tinvalid map", map, 1);
	return (map);
}

bool	empty_line(char **line, int fd)
{
	if (ft_isempty(*line))
	{
		ft_sfree(*line);
		*line = get_next_line(fd);
		return (true);
	}
	return (false);
}
