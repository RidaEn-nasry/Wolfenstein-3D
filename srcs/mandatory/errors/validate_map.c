/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:59:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/13 14:37:39 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>
#include <libft.h>

/** defualts:
 * if there's a missing value use a default one
 *
 *
 **/

/** checks:
 * if the map is not surronded by walls (one's) return an error.
 * if the map content is seperated by lines return an error
 * if the map content is not the last return an error 
 * if any of the sixth values is not starting or/and have a invalid identifier return an error
 * check validity of path to texture
 * if there's not sixth values return an error, done
**/

t_map	*init() {
	t_map	*map;
	exitif(!(map = malloc(sizeof(*map))), "Error\n\tmalloc error");
	exitif(!(map->txtr = malloc(sizeof(*map->txtr))), "Error\n\tmalloc error");
	exitif(!(map->clr = malloc(sizeof(*map->clr))), "Error\n\tmalloc error");
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
	
	path = ft_substr(line, ft_strchr(line, '/') - line - 1, ft_strlen(line));
	printf("path: %s\n", path);
	fd = open(path, O_RDONLY);
	if (open("/Users/ren-nasr/outfile", O_RDONLY) == -1)
		printf("cannot open absolute path\n");
	if (fd == -1)
		exitif(1, "Error\n\ttexture file not found");
	// exitif((fd = open(path, O_RDONLY)) == -1, "Error\n\ttexture file not found");
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
	int	i;
	
	i = 0;
	while (line[i] != 'F' || line[i] != 'C')
		i++;
	i += 1;
	while (ft_isspace(line[i]))
		i++;
	rgb = ft_split(&line[i], ',');
	exitif(!rgb, "Error:\n\tft_strsplit failed");
	while (rgb[i])
	{
		color = ft_atoi(rgb[i]);
		color = color << 8;
		exitif(color < 0 || color > 255, "Error\n\tcolor value out of range");	
		i++;
	}
	return (map);
}



t_map	*validate_map( char *map_file ) {	
	char		*line;
	int			fd;
	t_map		*map;


	exitif((fd = open(map_file, O_RDONLY)) == -1, "Error:\n\tinvalid map file");
	exitif((ft_strncmp(map_file + ft_strlen(map_file) - 4, ".cub", 4) != 0), "Error:\n\tinvalid map file. expected extension is .cub");
	exitif(ft_filecount(map_file) < 7, "Error:\n\tMissing values in map file");
	fd = open(map_file, O_RDONLY);
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
			{
				printf("%s\n", line);
				map = get_color(line, map);
			}
		}
		exitif(!is_map(line) && !is_identifier(line), "Error:\n\t unknown identifier in map");
		free(line);
		line = get_next_line(fd);
		
	}
	return (map);
}


int main( void ) {
	char *map_file = "/Users/ren-nasr/Wolfenstein-3D/resources/maps/map.cub";
	t_map *map = validate_map(map_file);
	(void)map;
	
	/*
	 *int fd = open(map_file, O_RDONLY);
	 *char *line = get_next_line(fd);
	 *while (line)
	 *{
	 *        printf("line: %s\n", line);
	 *        line = get_next_line(fd);
	 *}
	 */
	return (0);
} 
