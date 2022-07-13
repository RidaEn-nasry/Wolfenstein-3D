/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:13:47 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/13 13:29:01 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <libft.h>
# include <stdio.h>


typedef	struct s_textures {
	char			*north;
	char			*south;
	char			*east;
	char			*west;
} t_textures;

typedef struct s_colors {
	int			ceiling_color;
	int			floor_color;
} t_colors;


typedef struct s_map {
	unsigned long		width;
	unsigned long		height;
	char			**map;
	t_colors		*clr;
	t_textures		*txtr;
}t_map;


bool	is_identifier(char *line);
bool	is_map(char *line);
#endif
