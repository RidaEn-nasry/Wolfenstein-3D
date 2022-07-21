/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:24:51 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/21 01:51:25 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

bool	ray_is_down(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (true);
	return (false);	
}


bool	ray_is_right(double angle)
{
	if (angle < (M_PI / 2) || angle > (1.5 * M_PI))
		return (true);
	return (false);
}

double	normalize_ang(double angle)
{
	angle = fmod(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

void	cast(t_map *map, double ray_angl)
{
	double	xinter;
	double	yinter;
	double	nwall_x;
	double	nwall_y;
	int		index_x;
	int		index_y;

	ray_angl = normalize_ang(ray_angl);
	map->rndr->wall->found_h = false;	
	yinter = floor(map->rndr->pvec->y / CELL_SIZE) * CELL_SIZE;
	if (ray_is_down(ray_angl))
		yinter += CELL_SIZE;		
	xinter = map->rndr->pvec->x + (yinter - map->rndr->pvec->y) / tan(ray_angl);	
	map->rndr->wall->stepy = CELL_SIZE;
	if (!ray_is_down(ray_angl))
		map->rndr->wall->stepy *= -1;
	map->rndr->wall->stepx = CELL_SIZE / tan(ray_angl);
	if (ray_is_right(ray_angl) && map->rndr->wall->stepx < 0)
		map->rndr->wall->stepx *= -1;
	else if (!ray_is_right(ray_angl) && map->rndr->wall->stepx > 0)
		map->rndr->wall->stepx *= -1;
	nwall_x = xinter;
	nwall_y = yinter;
	
	if (!ray_is_down(ray_angl))
		nwall_y -= 1;
	while (nwall_x >= 0 && nwall_x <= (CELL_SIZE * map->w) && nwall_y >= 0 && nwall_y <= (CELL_SIZE * map->h))
	{
		index_x = nwall_x / CELL_SIZE;
		index_y = nwall_y / CELL_SIZE;
			
		printf("x: %d | y: %d\n", index_x, index_y);
		if (map->map[index_y][index_x] == '1')
		{
			map->rndr->wall->found_h = true;
			map->rndr->wall->wallx = nwall_x;
			map->rndr->wall->wally = nwall_y;
			// nwall_x = (map->rndr->pvec->x + (PLY_SIZE / 2)) + cos(ray_angl));
			// nwall_y = (map->rndr->pvec->y + (PLY_SIZE / 2)) + sin(ray_angl);
			bresenham(map, nwall_x, nwall_y, 0x03B965);
			break; 
		}
		else {
			nwall_x += map->rndr->wall->stepx;
			nwall_y += map->rndr->wall->stepy;
		}
	}
	
	
}

void	cast_rays(t_map *map)
{
	double	ray_angl;
	int	i;


	i = 0;
	ray_angl = map->rndr->rot_angl - (map->rndr->fov / 2);
	while (i < WIDTH)
	{
		cast(map, ray_angl);
		ray_angl += (map->rndr->fov / WIDTH);
		i++;
	}
}
