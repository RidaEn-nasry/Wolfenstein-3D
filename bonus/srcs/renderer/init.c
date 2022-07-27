/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:51:31 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/27 09:46:35 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	init_rndr_assist(t_map *map)
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
	exit_free_if(!(map->rndr->doors = malloc(sizeof(*map->rndr->doors))),
		"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(map->rndr->proj = malloc(sizeof(*map->rndr->proj))),
		"Error:\n\tmalloc failed", map, 1);
}

t_map	*init_rndr(t_map *map)
{
	init_rndr_assist(map);
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
	map->rndr->doors->door_txtr = "./resources/textures/metaldoor.xpm";
	map = init_mlx(map);
	return (map);
}

t_map	*new_img(t_map *map)
{
	exit_free_if(!(map->mlx->img
			= mlx_new_image(map->mlx->mlx, WIDTH, HEIGHT)),
		"Error:\n\tmlx image creation failed", map, 1);
	map->mlx->bpp = 32;
	map->mlx->size_line = WIDTH * 4;
	map->mlx->endian = 0;
	map->mlx->img_data = (int *)mlx_get_data_addr(map->mlx->img,
			&map->mlx->bpp, &map->mlx->size_line, &map->mlx->endian);
	return (map);
}

void	init_mlx_assist(t_map *map)
{
	exit_free_if(!(map->mlx = malloc(sizeof(*map->mlx))),
		"Error:\n\tmalloc failed", map, 1);
	exit_free_if(!(map->mlx->mlx = mlx_init()),
		"Error:\n\tmlx initilization failed", map, 1);
	exit_free_if(!(map->mlx->win
			= mlx_new_window(map->mlx->mlx, WIDTH, HEIGHT, "wolfenstein 3d")),
		"Error:\n\tmlx window creation failed", map, 1);
	exit_free_if(!(map->txtr->img = mlx_xpm_file_to_image(map->mlx->mlx,
				map->txtr->north, &map->txtr->w, &map->txtr->h)),
		"Error:\n\tmlx image creation failed", map, 1);
	map->txtr->north_data = (int *)mlx_get_data_addr(map->txtr->img,
			&map->txtr->bpp, &map->txtr->size_line, &map->txtr->endian);
	exit_free_if(!(map->txtr->img = mlx_xpm_file_to_image(map->mlx->mlx,
				map->txtr->south, &map->txtr->w, &map->txtr->h)),
		"Error:\n\tmlx image creation failed", map, 1);
	map->txtr->south_data = (int *)mlx_get_data_addr(map->txtr->img,
			&map->txtr->bpp, &map->txtr->size_line, &map->txtr->endian);
	exit_free_if(!(map->txtr->img = mlx_xpm_file_to_image(map->mlx->mlx,
				map->txtr->east, &map->txtr->w, &map->txtr->h)),
		"Error:\n\tmlx image creation failed", map, 1);
	map->txtr->west_data = (int *)mlx_get_data_addr(map->txtr->img,
			&map->txtr->bpp, &map->txtr->size_line, &map->txtr->endian);
}

t_map	*init_mlx(t_map	*map)
{
	init_mlx_assist(map);
	exit_free_if(!(map->txtr->img = mlx_xpm_file_to_image(map->mlx->mlx,
				map->txtr->west, &map->txtr->w, &map->txtr->h)),
		"Error:\n\tmlx image creation failed", map, 1);
	map->txtr->east_data = (int *)mlx_get_data_addr(map->txtr->img,
			&map->txtr->bpp, &map->txtr->size_line, &map->txtr->endian);
	exit_free_if(!(map->txtr->img = mlx_xpm_file_to_image(map->mlx->mlx,
				map->rndr->doors->door_txtr, &map->txtr->w, &map->txtr->h)),
		"Error:\n\tmlx image creation failed", map, 1);
	map->rndr->doors->door_data = (int *)mlx_get_data_addr(map->txtr->img,
			&map->txtr->bpp, &map->txtr->size_line, &map->txtr->endian);
	map = new_img(map);
	return (map);
}
