/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_drawers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:44:21 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 18:23:49 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	draw_square(t_map *map, int x, int y, int clr)
{
	int		i;
	int		j;
	int		size;

	size = CELL_SIZE * SCL_FAC;
	i = y;
	while (i < (y + size))
	{
		j = x;
		while (j < (x + size))
		{
			put_pix_to_img(map, j, i, clr);
			j++;
		}
		i++;
	}
}
