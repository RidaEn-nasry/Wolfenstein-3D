/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:13:47 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/18 13:47:40 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <libft.h>
# include <stdio.h>




typedef struct	s_vector {
	double	x;
	double	y;
}	t_vector;

typedef struct s_render {
	t_vector	*pvec;
	t_vector	*dvec;
	t_vector	*cvec;
	int		fov;
	int		time;
	int		old_time;
}	t_render;

// minilibx struct
typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
} t_mlx;

// Textures
typedef	struct s_textures {
	char			*north;
	char			*south;
	char			*east;
	char			*west;
} t_textures;


// Colors
typedef struct s_colors {
	int			ceiling;
	int			floor;
} t_colors;



// The grand struct
typedef struct s_map {
	unsigned long		w;
	unsigned long		h;
	char			**map;
	t_colors		*clr;
	t_textures		*txtr;
	t_mlx			*mlx;
	t_render		*rndr;
}t_map;


bool	is_identifier(char *line);
bool	is_map(char *line);
#endif
