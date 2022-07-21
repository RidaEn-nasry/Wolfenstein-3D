/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:24:51 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/21 21:25:22 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>



// void	draw_point(t_map *map, double x, double y, int clr)
// {
// 	for (int i = 0; i < 50; i++)
// 	{
// 		mlx_pixel_put(map->mlx->mlx, map->mlx->win, x, y, clr);
// 	}
// }

double	get_dist(double x0, double x1, double y0, double y1)
{
	return (sqrt(((x1 - x0) * (x1 - x0)) + ((y1 - y0) * (y1 - y0))));
}
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
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

t_wall	*cast_v(t_map *map, double ray_angl)
{
	double	xinter;
	double	yinter;
	int		index_x;
	int		index_y;
	double	nwall_x;
	double	nwall_y;
	t_wall	*tmp;
	bool	found;
	double	startx;
	double	starty;
	
	exit_free_if(!(tmp = malloc(sizeof(*tmp))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->wall = malloc(sizeof(*tmp->wall))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->step = malloc(sizeof(*tmp->step))), "Error:\n\tmalloc failed\n", map);
	startx = map->rndr->pvec->x + (PLY_SIZE / 2);
	starty = map->rndr->pvec->y + (PLY_SIZE / 2);
	
	found = false;
	xinter = floor(startx / CELL_SIZE) * CELL_SIZE;
	ray_angl = normalize_ang(ray_angl);
	if (ray_is_right(ray_angl))
		xinter += CELL_SIZE;
	yinter = starty + (xinter - startx) * tan(ray_angl);
	
	tmp->step->x = CELL_SIZE;
	if (!ray_is_right(ray_angl))
		tmp->step->x *= -1;
	tmp->step->y = CELL_SIZE * tan(ray_angl);
	if (!ray_is_down(ray_angl) && tmp->step->y > 0)
		tmp->step->y *= -1;
	else if (ray_is_down(ray_angl) && tmp->step->y < 0)
		tmp->step->y *= -1;

	nwall_x = xinter;
	nwall_y = yinter;
	
	if (!ray_is_right(ray_angl))
		nwall_x -= 1;
	while (nwall_x >= 0 && nwall_x <= (CELL_SIZE * map->w) && nwall_y >= 0 && nwall_y <= (CELL_SIZE * map->h))
	{
		index_x = nwall_x / CELL_SIZE;
		index_y = nwall_y / CELL_SIZE;
		
		if (map->map[index_y][index_x] == '1')
		{
			found = true;
			tmp->wall->x = nwall_x;
			tmp->wall->y = nwall_y;
			printf("x : %lf and y: %lf is inside a wall vecrtical\n", nwall_x, nwall_y);
			printf("index: map[%d][%d]\n", (int)(yinter  / CELL_SIZE), (int)(xinter / CELL_SIZE));
			// draw_point(map, nwall_x, nwall_y, 0x6633AA);
			break;
		}
		else {
			printf("x : %lf and y: %lf is not inside a wall vertical\n", xinter, yinter);
			printf("index: map[%d][%d]\n", (int)(yinter  / CELL_SIZE), (int)(xinter / CELL_SIZE));
			nwall_x += tmp->step->x;
			nwall_y += tmp->step->y;
		}
	}
	if (!found)
	{
		tmp->wall->x = (CELL_SIZE * map->w);
		tmp->wall->y = (CELL_SIZE * map->h);
	}
	return (tmp);	
}

t_wall	*cast_h(t_map *map, double ray_angl)
{
	double	xinter;
	double	yinter;
	int		index_x;
	int		index_y;
	double	nwall_x;
	double	nwall_y;
	
	
	double	startx;
	double	starty;

	t_wall	*tmp;
	bool	found;
	
	exit_free_if(!(tmp = malloc(sizeof(*tmp))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->wall = malloc(sizeof(*tmp->wall))), "Error:\n\tmalloc failed\n", map);
	exit_free_if(!(tmp->step = malloc(sizeof(*tmp->step))), "Error:\n\tmalloc failed\n", map);
	startx = map->rndr->pvec->x + (PLY_SIZE / 2);
	starty = map->rndr->pvec->y + (PLY_SIZE / 2);

	
	ray_angl = normalize_ang(ray_angl);	
	found = false;	
	yinter = floor(starty / CELL_SIZE) * CELL_SIZE;
	if (ray_is_down(ray_angl))
		yinter += CELL_SIZE;		
	// xinter = map->rndr->pvec->x + (yinter - map->rndr->pvec->y) / tan(ray_angl);
	xinter = startx + ((yinter - starty) / tan(ray_angl));
	xinter = startx + (yinter - starty) / tan(ray_angl);
	tmp->step->y = CELL_SIZE;
	if (!ray_is_down(ray_angl))
		tmp->step->y *= -1;
	tmp->step->x = CELL_SIZE / tan(ray_angl);
	if (ray_is_right(ray_angl) && tmp->step->x < 0)
		tmp->step->x *= -1;
	else if (!ray_is_right(ray_angl) && tmp->step->x > 0)
		tmp->step->x *= -1;
	
	nwall_x = xinter;
	nwall_y = yinter;
	
	if (!ray_is_down(ray_angl))
		nwall_y -= 1;
	while (nwall_x >= 0 && nwall_x <= (CELL_SIZE * map->w) && nwall_y >= 0 && nwall_y <= (CELL_SIZE * map->h))
	{
		index_x = nwall_x / CELL_SIZE;
		index_y = nwall_y / CELL_SIZE;
		if (map->map[index_y][index_x] == '1')
		{
			found = true;
			tmp->wall->x = nwall_x;
			tmp->wall->y = nwall_y;
			printf("x : %lf and y: %lf is inside a wall horizon\n", nwall_x, nwall_y);
			printf("index: map[%d][%d]\n", (int)(nwall_x  / CELL_SIZE), (int)(nwall_x / CELL_SIZE));
			// draw_point(map, nwall_x, nwall_y, 0x6633AA);
			break;
		}
		else {
			printf("x : %lf and y: %lf is not inside a wall horizon\n", xinter, yinter);
			printf("index: map[%d][%d]\n", (int)(yinter  / CELL_SIZE), (int)(xinter / CELL_SIZE));	
			nwall_x += tmp->step->x;
			nwall_y += tmp->step->y;
		}
	}
	if (!found)
	{
		mlx_pixel_put(map->mlx->mlx, map->mlx->win, xinter, yinter, 0xFF0000);
		tmp->wall->x = map->rndr->pvec->x + (CELL_SIZE * map->w);
		tmp->wall->y = map->rndr->pvec->y + (CELL_SIZE * map->h);
	}
	return (tmp);
}


void	cast(t_map *map, double ray_angl)
{	
	t_wall	*wall_h;
	t_wall	*wall_v;
	t_wall	*end;
	wall_h = cast_h(map, ray_angl);
	wall_v = cast_v(map, ray_angl);
	// printf("distance hori: %lf\n", get_dist(map->rndr->pvec->x, wall_h->wall->x, map->rndr->pvec->y, wall_h->wall->y));
	// printf("distance ver: %lf\n", get_dist(map->rndr->pvec->x, wall_v->wall->x, map->rndr->pvec->y, wall_v->wall->y));
	

	double startx = map->rndr->pvec->x + (CELL_SIZE / 2);
	double starty = map->rndr->pvec->y  + (CELL_SIZE / 2); 
	// // double	endx = wall_h->wall->x + (CELL_SIZE / 2);
	
	double	distanceh = get_dist( startx, wall_h->wall->x, starty, wall_h->wall->y);
	double	distancev = get_dist( startx, wall_v->wall->x, starty, wall_v->wall->y);

	if ( distanceh <= distancev)
		end = wall_h;
	else
		end = wall_v;
	// end = cast_v(map, ray_angl);
	// if (end->wall->x == INT_MAX || end->wall->y == INT_MAX)
	// {
	// 	printf("value is int max\n");
	// 	exit(1);
	// }
	// if (wall_h->wall->x == INT_MAX || wall_h->wall->y == INT_MAX)
	// 	end = wall_v;
	// if (wall_v->wall->y == INT_MAX || wall_v->wall->y == INT_MAX)
	// 	end = wall_h;
	bresenham(map, end->wall->x, end->wall->y, 0x03B965);
	
}

void	cast_rays(t_map *map)
{
	double	ray_angl;
	int	i;

	i = 0;
	ray_angl = map->rndr->rot_angl - (map->rndr->fov / 2);
	while (i < WIDTH)
	{
		printf("************* %d *********************************\n", i);
		cast(map, ray_angl);
		ray_angl += (map->rndr->fov / WIDTH);
		i++;
	}
}
