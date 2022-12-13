/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 09:13:47 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/28 22:47:26 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define WIDTH 1920
# define HEIGHT 1080

# include <libft.h>
# include <stdio.h>
# include <math.h>
# include <signal.h>

typedef struct s_vector {
	double	x;
	double	y;
}	t_vector;

typedef struct s_v {
	int	x;
	int	y;
}	t_v;

typedef struct s_darr {
	double	*arr;
	size_t	len;
}			t_darr;

typedef struct s_3dproj {
	double			proj_plan;
	double			wall_proj_height;
	int				botom_pix;
	int				top_pix;
}				t_3dproj;

typedef struct s_varr {
	t_vector	*vec;
	size_t		len;
}	t_varr;

typedef struct s_wall {
	t_vector	*wall;
	double		ray_angl;
	int			wall_top_pixel;
	int			wall_height;
	t_vector	*step;
	double		arr_dist[WIDTH];
	double		arr_angl[WIDTH];
	t_vector	rays[WIDTH];
	bool		vert[WIDTH];
	bool		horiz[WIDTH];
	size_t		len_arr;
	size_t		rys_len;
}				t_wall;

typedef struct s_door {
	char	*door_txtr;
	int		*door_data;
	char	**map_cpy;
}			t_door;

// struct of variables needed in draw_map
typedef struct s_drawmap {
	int		x;
	int		y;
	bool	p;
	int		i;
	int		j;
}				t_drawmap;

typedef struct s_render {
	t_vector	*pvec;
	double		fov;
	int			turn_dir;
	int			walk_dir;
	double		rot_angl;
	double		walk_spd;
	double		turn_spd;
	t_door		*doors;
	t_wall		*wall;
	t_3dproj	*proj;
	pid_t		music;
}	t_render;

typedef struct s_moves {
	double	x;
	double	y;
	int		index_x;
	int		index_y;
	int		incx;
	int		incy;
	int		i;
}				t_moves;

// minilibx struct
typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	int		*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_mlx;

// Textures
typedef struct s_textures {
	void			*img;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	int				bpp;
	int				size_line;
	int				endian;
	bool			found_h;
	bool			found_v;
	int				*north_data;
	int				*south_data;
	int				*east_data;
	int				*west_data;
	int				*data_v;
	int				*data_h;
	int				*data;
	int				w;
	int				h;
}			t_textures;

// Colors
typedef struct s_colors {
	int			ceiling;
	int			floor;
}			t_colors;

// The grand struct
typedef struct s_map {
	unsigned long		w;
	unsigned long		h;
	char				**map;
	char				**env;
	t_v					clr_txtr_count;
	t_colors			*clr;
	t_textures			*txtr;
	t_mlx				*mlx;
	t_render			*rndr;
}				t_map;

bool	is_identifier(char *line);
bool	is_map(char *line);

#endif
