/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:13:47 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/10 17:34:13 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <libft.h>
# include <stdio.h>


typedef struct s_map {
	unsigned long		width;
	unsigned long		height;
	char			**map;
	int			ceiling_color;
	int			floor_color;
	char			*north_texture;
	char			*south_texture;
	char			*east_texture;
	char			*west_texture;
}t_map;




bool	is_identifier(char *line);
bool	is_map(char *line);
#endif
