/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:59:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/27 09:47:58 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errors.h>

/** checks:
 * if the map is not surronded by walls (one's) return an error. done
 * if the map content is seperated by lines return an error,  done
 * if the map content is not the last return an error , done
 * if any of the sixth values is not starting or/and have a 
 * invalid identifier return an error, done
 * check validity of path to texture, done
 * if there's not sixth values return an error, done
**/

int	get_map_assist(t_map *map, char *line, int *height, bool prev_isempty)
{
	char	*hold;

	if (!is_map(line))
		return (1);
	hold = ft_substr(line, 0, ft_strlen(line) - 1);
	exit_free_if(is_map(hold) && prev_isempty,
		"Error:\n\tmap should be be seperated by empty lines", map, 1);
	free(hold);
	if (!prev_isempty)
	{
		exit_free_if(line[0] != '1' || line[ft_strlen(line) - 2] != '1',
			"Error:\n\tmap should be surrounded by walls", map, 1);
		hold = ft_substr(line, 0, ft_strlen(line) - 1);
		map->map = ft_2darr_add(map->map, hold);
		free(hold);
		(*height)++;
	}
	return (0);
}

t_map	*get_map(int fd, t_map *map)
{
	char	*line;
	bool	prev_isempty;
	int		height;

	line = get_next_line(fd);
	prev_isempty = false;
	height = 1;
	while (line)
	{
		if (ft_isempty(line))
		{
			prev_isempty = true;
			free(line);
			line = get_next_line(fd);
		}
		if (get_map_assist(map, line, &height, prev_isempty))
			return (NULL);
		free(line);
		line = get_next_line(fd);
	}
	map->h = height;
	map->w = ft_strlen(map->map[0]);
	return (map);
}
