/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:59:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 23:00:16 by mkarim           ###   ########.fr       */
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
	bool	ismap;

	ismap = is_map(line);
	if (!ismap)
		return (1);
	exit_free_if(ismap && prev_isempty,
		"Error:\n\tmap should be be seperated by empty lines", map, 1);
	if (!prev_isempty)
	{	
		map->map = ft_2darr_add(map->map, line);
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
		line = check_line_get_mp(line);
		if (ft_isempty(line))
		{
			prev_isempty = true;
			ft_sfree(line);
			line = get_next_line(fd);
			continue ;
		}
		if (get_map_assist(map, line, &height, prev_isempty))
			return (NULL);
		ft_sfree(line);
		line = get_next_line(fd);
	}
	map->h = height;
	map->w = ft_strlen(map->map[0]);
	return (map);
}
