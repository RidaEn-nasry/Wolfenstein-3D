/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:59:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 23:32:12 by ren-nasr         ###   ########.fr       */
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
bool	isempty_get_map(char **line, int fd, bool *prev_isempty)
{
	if (ft_isempty(*line))
	{
		*prev_isempty = true;
		ft_sfree(*line);
		*line = get_next_line(fd);
		return (true);
	}
	return (false);
}

void	check_is_indetifier(t_map *map, char *line)
{
	if (is_identifier(line))
	{
		if (ft_strchr(line, '/'))
			map = get_texture(line, map);
		else
			map = get_color(line, map);
	}
}

void	exit_if_assist(char *map_file, int *fd)
{
	exitif((*fd = open(map_file, O_RDONLY)) == -1, "Error:\n\tinvalid map file");
	exitif((ft_strncmp(map_file + ft_strlen(map_file) - 4, ".cub", 4) != 0),
		"Error:\n\tinvalid map file. expected extension is .cub");
	exitif(ft_filelcount(map_file) < 7, "Error:\n\tMissing values in map file");
	exitif(!map_is_last(map_file),
		"Error:\n\tMap content should be at the end of the file");
}

void	is_map_assist(t_map	*map, int fd, char *line)
{
	line = check_line(line);
	ft_doubfree((void **)map->map, 0);
	map->map = malloc(sizeof(char *) * 2);
	map->map[0] = line;
	map->map[1] = NULL;
	map = get_map(fd, map);
	exit_free_if(!map, "Error:\n\tInvalid map", map, 1);
}

t_map	*validate_map(char *map_file)
{
	char		*line;
	int			fd;
	t_map		*map;

	map = NULL;
	exit_if_assist(map_file, &fd);
	line = get_next_line(fd);
	map = map_init(map, map_file);
	while (line != NULL)
	{
		if (empty_line(&line, fd))
			continue ;
		check_is_indetifier(map, line);
		if (is_map(line))
		{
			is_map_assist(map, fd, line);
			break ;
		}
		ft_sfree(line);
		line = get_next_line(fd);
	}
	exit_free_if(map->clr_txtr_count.x != 2 || \
	map->clr_txtr_count.y != 4, "Error:\n\t invalid arguments in map", map, 1);
	return (close(fd), map);
}
