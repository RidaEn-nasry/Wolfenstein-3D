/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:44:15 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 23:32:27 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <parser.h>
# include <mlx.h>

void	exit_free_if(int cond, char *msg, t_map *map, int code);
t_map	*validate_map(char *map_file);
t_map	*init(void);
t_map	*get_texture(char *line, t_map *map);
void	get_color_assist(t_map *map, char c, int color);
t_map	*get_color(char *line, t_map *map);
bool	map_is_last(char *map_file);
void	check_is_indetifier(t_map *map, char *line);
void	exit_if_assist(char *map_file, int *fd);
void	is_map_assist(t_map	*map, int fd, char *line);
t_map	*validate_map(char *map_file);
int		get_map_assist(t_map *map, char *line, int *height, bool prev_isempty);
t_map	*get_map(int fd, t_map *map);
bool	is_txtr(char c);
char	*check_line(char *line);
char	**get_new_map(char **map);
bool	check_map(char **map);
void	skip_spcs(char **map, int *i);
char	*add_spaces(char *line, size_t maxlen);
size_t	get_max(char **map);
bool	all_ones(char *line);
bool	valid(char **line, int i, int j);
bool	check_plyr(char **map, int i, int j);
bool	is_plyr(char c);
char	*check_line(char *line);
char	*check_line_get_mp(char *line);
char	**get_rgb(char *line, char **temp, t_map *map);
t_map	*map_init(t_map *map, char *map_file);
bool	empty_line(char **line, int fd);
bool	isempty_get_map(char **line, int fd, bool *prev_isempty);
#endif
