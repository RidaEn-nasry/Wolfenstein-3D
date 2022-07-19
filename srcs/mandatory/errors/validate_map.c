/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:59:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/19 10:17:03 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <parser.h>
#include <errors.h>

/** checks:
 * if the map is not surronded by walls (one's) return an error. done
 * if the map content is seperated by lines return an error,  done
 * if the map content is not the last return an error , done
 * if any of the sixth values is not starting or/and have a invalid identifier return an error, done
 * check validity of path to texture, done
 * if there's not sixth values return an error, done
**/

t_map	*init() {
	t_map	*map;
	exitif(!(map = malloc(sizeof(*map))), "Error\n\tmalloc error");
	exit_free_if(!(map->txtr = malloc(sizeof(*map->txtr))), "Error\n\tmalloc error", map);
	exit_free_if(!(map->clr = malloc(sizeof(*map->clr))), "Error\n\tmalloc error", map);
	map->map = NULL;
	map->txtr->east = NULL;
	map->txtr->west = NULL;
	map->txtr->north = NULL;
	map->txtr->south = NULL;
	return (map);
}

t_map	*get_texture(char *line, t_map *map)
{
	char	*path;
	int		fd;

	path = ft_substr(line, ft_strchr(line, '/') - line - 1, ft_strlen(line) - 1);
	path = ft_strtrim(path, " ");
	exit_free_if((fd = open(path, O_RDONLY)) == -1, "Error:\n\ttexture file not found", map);
	if (line[0] == 'N' && line[1] == 'O')
		map->txtr->north = path;
	else if (line[0] == 'S' && line[1] == 'O')
		map->txtr->south = path;
	else if (line[0] == 'E' && line[1] == 'E')
		map->txtr->east = path;
	else if (line[0] == 'W' && line[1] == 'E')
		map->txtr->west = path;
	return (map);
}

t_map	*get_color(char *line, t_map *map) {
	
	char	**rgb;
	int		color;
	int		tmp;
	int	i;

	color = 0;
	i = 0;
	while (line[i] != 'F' && line[i] != 'C')
		i++;
	i += 1;
	while (ft_isspace(line[i]))
		i++;
	rgb = ft_split(&line[i], ',');
	exit_free_if(!rgb, "Error:\n\tft_split failed", map);
	i = 0;
	while (rgb[i])
	{		
		rgb[i] = ft_strtrim(rgb[i], "\n");
		exit_free_if(!ft_isnumber(rgb[i]), "Error:\n\tinvalid rgb value", map);
		tmp = ft_atoi(rgb[i]);
		exit_free_if(tmp < 0 || tmp > 255, "Error\n\tcolor value out of range", map);	
		color += tmp << (i * 8);
		i++;
	}
	if (line[0] == 'F')
		map->clr->floor = color;
	else if (line[0] == 'C')
		map->clr->ceiling = color;
	return (map);
}


bool	map_is_last( char *map_file) {
	char	**lines;
	size_t	len;

	lines = ft_file_to_2darr(map_file);
	exitif(!lines, "Error:\n\tmalloc failed");	
	len = ft_2darr_len((const char**)lines);
	while (ft_isempty(lines[len - 1]))
		len--;
	if (!is_map(lines[len - 1]))
		return (false);
	
	return (true);	
};

t_map	*get_map( int fd, t_map *map) {
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
		exit_free_if(is_map(ft_substr(line, 0, ft_strlen(line) - 1)) && prev_isempty, "Error:\n\tmap should be be seperated by empty lines", map);
		
		if (!prev_isempty)
		{
			exit_free_if(line[0] != '1' || line[ft_strlen(line) - 2] != '1', "Error:\n\tmap should be surrounded by walls", map);
			map->map = ft_2darr_add(map->map, ft_substr(line, 0, ft_strlen(line) - 1));	
			height++;
		}
		free(line);
		line = get_next_line(fd);
	}
	map->h = height;
	map->w = ft_strlen(map->map[0]);
	return (map);
}

t_map	*validate_map( char *map_file ) {	
	char		*line;
	int			fd;
	t_map		*map;
	
	exitif((fd = open(map_file, O_RDONLY)) == -1, "Error:\n\tinvalid map file");
	exitif((ft_strncmp(map_file + ft_strlen(map_file) - 4, ".cub", 4) != 0), "Error:\n\tinvalid map file. expected extension is .cub");
	exitif(ft_filelcount(map_file) < 7, "Error:\n\tMissing values in map file");
	exitif(!map_is_last(map_file), "Error:\n\tMap content should be at the end of the file");
	
	line = get_next_line(fd);
	map = init();
	while (line != NULL)
	{
		if (ft_isempty(line)) {
			free(line);
			line = get_next_line(fd);
			continue;
		}
		if (is_identifier(line))
		{
			if (ft_strchr(line, '/'))
				map = get_texture(line, map);
			else 
				map = get_color(line, map);
		}
		else if (is_map(line))
		{
			exit_free_if(!ft_strofonly(ft_substr(line, 0, ft_strlen(line) - 1), "1"), "Error:\n\tmap should be surrounded by walls", map);
			map->map = malloc(sizeof(char *) * 2);
			map->map[0] = ft_substr(line, 0, ft_strlen(line) - 1);
			map->map[1] = NULL;
			map = get_map(fd, map);
			exit_free_if(!ft_strofonly(map->map[ft_2darr_len((const char**)map->map) - 1], "1"), "Error:\n\tmap should be surrounded by walls", map);
			break;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

