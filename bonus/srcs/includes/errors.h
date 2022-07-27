/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:44:15 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/27 09:43:45 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <parser.h>
# include <mlx.h>

void	exit_free_if(int cond, char *msg, t_map *map, int code);
t_map	*init(void);
t_map	*get_texture(char *line, t_map *map);
void	get_color_assist(t_map *map, char c, int color);
t_map	*get_color(char *line, t_map *map);
bool	map_is_last(char *map_file);
void	check_is_indetifier(t_map *map, char *line);
void	exit_if_assist(char *map_file, int *fd);
void	is_map_assist(t_map	*map, int fd, char *line);
t_map	*validate_map(char *map_file, char **env);
int		get_map_assist(t_map *map, char *line, int *height, bool prev_isempty);
t_map	*get_map(int fd, t_map *map);

#endif
