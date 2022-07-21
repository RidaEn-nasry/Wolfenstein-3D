/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:30:07 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 00:25:49 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	put_pix_to_img(t_map *map, int x, int y, int clr)
{
	char	*pixel;
	// exit_free_if(x > WIDTH, "x out of range",map);
	pixel = map->mlx->img_data + (y * map->mlx->size_line + x * (map->mlx->bpp / 8));
	*(unsigned int *)pixel = clr;
}


