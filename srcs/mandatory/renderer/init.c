/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:51:31 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/21 01:14:05 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <renderer.h>

t_map   *init_rndr(t_map *map)
{
	exit_free_if(!(map->rndr = malloc(sizeof(*map->rndr))), "Error:\n\tmalloc failed", map);
	exit_free_if(!(map->rndr->pvec = malloc(sizeof(*map->rndr->pvec))), "Error:\n\tmalloc failed", map);
	exit_free_if(!(map->rndr->wall = malloc(sizeof(*map->rndr->wall))), "Error:\n\tmalloc failed", map);
	map->rndr->wall->wallx = 0;
	map->rndr->wall->wally = 0;
	map->rndr->wall->dist = 0;
	map->rndr->wall->stepx = 0;
	map->rndr->wall->stepy= 0;

	
	/*map->rndr->pvec->y = 1;*/
	map->rndr->turn_dir = 0;
	map->rndr->walk_dir = 0;
	map->rndr->rot_angl = degtorad(90);
	map->rndr->walk_spd = 5;
	map->rndr->turn_spd = degtorad(10);
	map->rndr->fov = degtorad(60);
	map->clr->floor = 0xFF0000;
	map = init_mlx(map);
	return (map);
}

t_map	*new_img(t_map *map)
{
	/*ft_sfree(map->mlx->img);*/
	exit_free_if(!(map->mlx->img = mlx_new_image(map->mlx->mlx, WIDTH, HEIGHT)), "Error:\n\tmlx image creation failed", map);
	map->mlx->bpp = 32;
	map->mlx->size_line = WIDTH * 4;
	map->mlx->endian = 0;
	map->mlx->img_data = mlx_get_data_addr(map->mlx->img, &map->mlx->bpp, &map->mlx->size_line, &map->mlx->endian);
	return (map);
}

t_map	*init_mlx(t_map	*map)
{
	exit_free_if(!(map->mlx = malloc(sizeof(*map->mlx))), "Error:\n\tmalloc failed", map);
	exit_free_if(!(map->mlx->mlx = mlx_init()), "Error:\n\tmlx initilization failed", map);
	exit_free_if(!(map->mlx->win = mlx_new_window(map->mlx->mlx, WIDTH, HEIGHT, "wolfenstein 3d")), "Error:\n\tmlx window creation failed", map);
	map = new_img(map);
	return (map);
}


