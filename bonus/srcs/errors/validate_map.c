/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:59:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 22:55:20 by mkarim           ###   ########.fr       */
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

t_map	*init(void)
{
	t_map	*map;

	exitif(!(map = malloc(sizeof(*map))),
		"Error\n\tmalloc error");
	exit_free_if(!(map->txtr = malloc(sizeof(*map->txtr))),
		"Error\n\tmalloc error", map, 1);
	exit_free_if(!(map->clr = malloc(sizeof(*map->clr))),
		"Error\n\tmalloc error", map, 1);
	map->clr_txtr_count.x = 0;
	map->clr_txtr_count.y = 0;
	map->map = NULL;
	map->txtr->east = NULL;
	map->txtr->west = NULL;
	map->txtr->north = NULL;
	map->txtr->south = NULL;
	map->rndr = NULL;
	map->mlx = NULL;
	return (map);
}

t_map	*get_texture(char *line, t_map *map)
{
	char	*path;
	char	*hold;
	int		fd;
	int		i;

	i = 0;
	while (is_txtr(line[i]))
		i++;
	hold = ft_substr(line, i, ft_strlen(line) - 1);
	path = ft_strtrim(hold, " ");
	exit_free_if((fd = open(path, O_RDONLY) == -1),
		"Error\n\ttexture file not found", map, 1);
	if (line[0] == 'N' && line[1] == 'O')
		map->txtr->north = path;
	else if (line[0] == 'S' && line[1] == 'O')
		map->txtr->south = path;
	else if (line[0] == 'E' && line[1] == 'A')
		map->txtr->east = path;
	else if (line[0] == 'W' && line[1] == 'E')
		map->txtr->west = path;
	ft_sfree(hold);
	map->clr_txtr_count.y += 1;
	return (map);
}

void	init_and_scape_spc(char *line, int *i, int *color)
{
	*color = 0;
	*i = 0;
	while (line[*i] != 'F' && line[*i] != 'C')
		(*i)++;
	(*i) += 1;
	while (ft_isspace(line[*i]))
		(*i)++;
}

t_map	*get_color(char *line, t_map *map)
{
	char	**rgb;
	int		color;
	int		tmp;
	int		i;
	char	**temp;

	init_and_scape_spc(line, &i, &color);
	temp = ft_split(&line[i], ',');
	exit_free_if(!temp, "Error:\n\tft_split failed", map, 1);
	rgb = ft_2darr_trim(temp, " ");
	exit_free_if(ft_2darr_len((const char **)rgb) != 3,
		"Error\n\tcolor format error", map, 1);
	i = -1;
	while (rgb[++i])
	{
		exit_free_if(ft_isempty(rgb[i]), "Error:\n\tinvalid rgb value", map, 1);
		if (rgb[i][ft_strlen(rgb[i]) - 1] == '\n')
			rgb[i][ft_strlen(rgb[i]) - 1] = '\0';
		exit_free_if(!ft_isnumber(rgb[i]), "Error:\n\tinvalid rgb value", map, 1);
		tmp = ft_atoi(rgb[i]);
		exit_free_if(tmp < 0 || tmp > 255, "Err:\n\tcolor out of range", map, 1);
		color += tmp * pow(256, 2 - i);
	}
	get_color_assist(map, line[0], color);
	return (ft_doubfree((void **)rgb, 0), map);
}

bool	map_is_last(char *map_file)
{
	char	**lines;
	size_t	len;

	lines = ft_file_to_2darr(map_file);
	exitif(!lines, "Error:\n\tmalloc failed");
	len = ft_2darr_len((const char **)lines);
	while (ft_isempty(lines[len - 1]))
		len--;
	if (!is_map(lines[len - 1]))
	{
		ft_doubfree((void **)lines, ft_2darr_len((const char **)lines));
		return (false);
	}
	ft_doubfree((void **)lines, ft_2darr_len((const char **)lines));
	return (true);
}
