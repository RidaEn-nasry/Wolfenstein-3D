/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:43:40 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 22:21:01 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

double	degtorad(double degree)
{
	return (degree * M_PI / 180);
}

double	get_dist(double x0, double x1, double y0, double y1)
{
	return (sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0))));
}

void	init_angl(t_map *map, char c)
{
	if (c == 'N')
		map->rndr->rot_angl = degtorad(270);
	if (c == 'W')
		map->rndr->rot_angl = degtorad(180);
	if (c == 'S')
		map->rndr->rot_angl = degtorad(90);
	if (c == 'E')
		map->rndr->rot_angl = degtorad(0);
}

bool	isplayer(char c)
{
	if (c == 'N')
		return (true);
	if (c == 'E')
		return (true);
	if (c == 'S')
		return (true);
	if (c == 'W')
		return (true);
	return (false);
}
