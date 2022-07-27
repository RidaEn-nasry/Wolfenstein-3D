/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:51:31 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/27 09:57:44 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	check_exit_free(t_map *map)
{
	exit_free_if(!(map->rndr = malloc(sizeof(*map->rndr))),
		"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(map->rndr->pvec = malloc(sizeof(*map->rndr->pvec))),
		"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(map->rndr->wall = malloc(sizeof(*map->rndr->wall))),
		"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(map->rndr->wall->wall
			= malloc(sizeof(*map->rndr->wall->wall))),
		"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(map->rndr->wall->step
			= malloc(sizeof(*map->rndr->wall->step))),
		"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(map->txtr->north_vec
			= malloc(sizeof(*map->txtr->north_vec))),
		"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(map->rndr->proj
			= malloc(sizeof(*map->rndr->proj))),
		"Error:\n\tmalloc failed", map, 1);
}

t_map	*init_rndr(t_map *map)
{
	check_exit_free(map);
	map->rndr->wall->len_arr = 0;
	map->rndr->wall->rys_len = 0;
	map->rndr->wall->wall->x = 0;
	map->rndr->wall->wall->y = 0;
	map->rndr->wall->step->x = 0;
	map->rndr->wall->step->y = 0;
	map->rndr->turn_dir = 0;
	map->rndr->walk_dir = 0;
	map->rndr->walk_spd = 8;
	map->rndr->turn_spd = degtorad(10);
	map->rndr->fov = degtorad(60);
	map = init_mlx(map);
	return (map);
}

t_map	*new_img(t_map *map)
{
	exit_free_if(!(map->mlx->img = mlx_new_image(map->mlx->mlx,
				WIDTH, HEIGHT)), "Error:\n\tmlx image creation failed", map, 1);
	map->mlx->bpp = 32;
	map->mlx->size_line = WIDTH * 4;
	map->mlx->endian = 0;
	map->mlx->img_data = (int *)mlx_get_data_addr(map->mlx->img, &map->mlx->bpp,
			&map->mlx->size_line, &map->mlx->endian);
	return (map);
}

void	mlx_init_txtr(t_map *map)
{
	map->txtr->north_data = (int *)mlx_get_data_addr(map->txtr->img_n,
			&map->txtr->bpp, &map->txtr->size_line, &map->txtr->endian);
	map->txtr->south_data = (int *)mlx_get_data_addr(map->txtr->img_s,
			&map->txtr->bpp, &map->txtr->size_line, &map->txtr->endian);
	map->txtr->west_data = (int *)mlx_get_data_addr(map->txtr->img_w,
			&map->txtr->bpp, &map->txtr->size_line, &map->txtr->endian);
	map->txtr->east_data = (int *)mlx_get_data_addr(map->txtr->img_e,
			&map->txtr->bpp, &map->txtr->size_line, &map->txtr->endian);
}

t_map	*init_mlx(t_map	*map)
{
	exit_free_if(!(map->mlx = malloc(sizeof(*map->mlx))),
		"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(map->mlx->mlx = mlx_init()),
		"Error:\n\tmlx initilization failed", map, 1);
	exit_free_if(!(map->mlx->win = mlx_new_window(map->mlx->mlx, WIDTH,
				HEIGHT, "wolfenstein 3d")),
		"Error:\n\tmlx window creation failed", map, 1);
	exit_free_if(!(map->txtr->img_n = mlx_xpm_file_to_image(map->mlx->mlx,
				map->txtr->north, &map->txtr->w, &map->txtr->h)),
		"Error:\n\tmlx image creation failed", map, 1);
	exit_free_if(!(map->txtr->img_s = mlx_xpm_file_to_image(map->mlx->mlx,
				map->txtr->south, &map->txtr->w, &map->txtr->h)),
		"Error:\n\tmlx image creation failed", map, 1);
	exit_free_if(!(map->txtr->img_e = mlx_xpm_file_to_image(map->mlx->mlx,
				map->txtr->east, &map->txtr->w, &map->txtr->h)),
		"Error:\n\tmlx image creation failed", map, 1);
	exit_free_if(!(map->txtr->img_w = mlx_xpm_file_to_image(map->mlx->mlx,
				map->txtr->west, &map->txtr->w, &map->txtr->h)),
		"Error:\n\tmlx image creation failed", map, 1);
	mlx_init_txtr(map);
	map = new_img(map);
	return (map);
}
