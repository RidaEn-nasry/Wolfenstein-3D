/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:30:07 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 14:05:36 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	put_pix_to_img(t_map *map, int x, int y, int clr)
{
	char	*pixel;
	// exit_free_if(x > WIDTH, "x out of range",map);

	// if ( x >= WIDTH || y >= HEIGHT)
	// {
	// 	x = WIDTH - 2;
	// 	y = HEIGHT - 2;
	// }
	
	if (x >= WIDTH)
		x = WIDTH - 1;
	if (x < 0)
		x = 0;
	if (y >= HEIGHT)
		y = HEIGHT - 1;
	if (y < 0)
		y = 0;
	pixel = map->mlx->img_data + (y * map->mlx->size_line + x * (map->mlx->bpp / 8));
	*(unsigned int *)pixel = clr;
}


