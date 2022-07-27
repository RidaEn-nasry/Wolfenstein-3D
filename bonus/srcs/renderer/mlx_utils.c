/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:30:07 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 18:26:34 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	put_pix_to_img(t_map *map, int x, int y, int clr)
{
	if (x > WIDTH)
		x = WIDTH;
	if (x < 0)
		x = 0;
	if (y > HEIGHT)
		y = HEIGHT;
	if (y < 0)
		y = 0;
	(void)clr;
	map->mlx->img_data[y * WIDTH + x] = clr;
}
