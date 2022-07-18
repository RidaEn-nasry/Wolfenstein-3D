/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 10:11:27 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/18 22:40:39 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

/**
 * @brief given a map of 0 and 1 render a 2d scene with 0 as white squaures and 1 as black squares 
 * 
 * @param map the struct that contains the map to render
 */

/**


 * Cube(wall) size is 64x64x64
 * walls are always 90 degrees to the floor
 *  floor is always flat 
 * FOV of the player is 60 degrees (FOV determines how wide the world looks in fron of the player)
 * the player height is 32 units (half the cube size) 
 * 
 */


void	cast_rays() {/*cast all rays here*/}



void	move_ply(t_map *map)
{
	map->rndr->pvec->x += 1;
	map->rndr->pvec->y += 1;
}


void	draw_rect(t_map *map)
{
	int	x = map->rndr->pvec->x + 10;
	int	y = map->rndr->pvec->y + 10;
	char	*c;
	for (int i = map->rndr->pvec->y; i < y; i++)
	{
		for (int j = map->rndr->pvec->x; j < x; j++)
		{
			c = map->mlx->data + (i * map->mlx->size_line + j * (map->mlx->bpp / 8)); 
			*(int *)c = map->clr->floor;
		}
	}
	map->rndr->pvec->x += 10;
	map->rndr->pvec->y += 10;
}

t_map   *init_rndr(t_map *map)
{

	exit_free_if(!(map->mlx = malloc(sizeof(*map->mlx))), "Error:\n\tmalloc failed", map);
	exit_free_if(!(map->mlx->mlx = mlx_init()), "Error:\n\tmlx initilization failed", map);
	exit_free_if(!(map->mlx->win = mlx_new_window(map->mlx->mlx, WIDTH, HEIGHT, "wolfenstein 3d")), "Error:\n\tmlx window creation failed", map);
	exit_free_if(!(map->mlx->img = mlx_new_image(map->mlx->mlx, WIDTH, HEIGHT)), "Error:\n\tmlx image creation failed", map);
	map->mlx->bpp = 32;
	map->mlx->size_line = WIDTH * 4;
	map->mlx->endian = 0;
	map->mlx->data = mlx_get_data_addr(map->mlx->win, &map->mlx->bpp, &map->mlx->size_line, &map->mlx->endian);
	exit_free_if(!(map->rndr = malloc(sizeof(*map->rndr))), "Error:\n\tmalloc failed", map);
	exit_free_if(!(map->rndr->pvec = malloc(sizeof(*map->rndr->pvec))), "Error:\n\tmalloc failed", map);
	exit_free_if(!(map->rndr->dvec = malloc(sizeof(*map->rndr->dvec))), "Error:\n\tmalloc failed", map);
	exit_free_if(!(map->rndr->cvec = malloc(sizeof(*map->rndr->cvec))), "Error:\n\tmalloc failed", map);
	map->rndr->pvec->x = 0;
	map->rndr->pvec->y = 0;
	map->clr->floor = 0xFF0000;
	
	/*
	 *map->rndr->dvec->x = -1;
	 *map->rndr->dvec->y = 0;
	 *map->rndr->cvec->x = 0;
	 *map->rndr->cvec->y = 0.66;
	 *map->rndr->time = 0;
	 *map->rndr->old_time = 0;
	 */
	return (map);
}

void    render_map(t_map *map)
{
		map = init_rndr(map);
		draw_rect(map);
		mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);
		mlx_clear_window(map->mlx->mlx, map->mlx->win);
		mlx_loop(map->mlx->mlx);
}

