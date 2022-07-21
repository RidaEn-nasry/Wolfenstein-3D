/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:13:47 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/21 00:42:21 by ren-nasr         ###   ########.fr       */
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
	int				ceiling_color;
	int				floor_color;
	char			*north_texture;
	char			*south_texture;
	char			*east_texture;
	char			*west_texture;
}t_map;




bool	isIdentifier(char *line);
bool	isMap(char *line);
#endif
