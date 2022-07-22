/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:09:17 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 14:09:22 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	update_pos(double *x, double *y, t_map *map)
{
	int	move_step;

	move_step = map->rndr->walk_dir * map->rndr->walk_spd;

	*x += (cos(map->rndr->rot_angl) * move_step);
	*y += (sin(map->rndr->rot_angl) * move_step);
}

void	update_ang(t_map *map) 
{
	
	map->rndr->rot_angl += (map->rndr->turn_dir * map->rndr->turn_spd);
}

bool	inside_wall(double x, double y, t_map *map)
{
	x = map->rndr->pvec->x;
	y = map->rndr->pvec->y;
	
	for (int i = 0, incx = 0, incy = 0; i < 4; i++)
	{
		x = map->rndr->pvec->x + incx;
		y = map->rndr->pvec->y + incy;
		update_pos(&x, &y, map);

		int index_x = x / CELL_SIZE;
		int index_y = y / CELL_SIZE;
		
		if (map->map[index_y][index_x] == '1')
			return (true);
		if (i == 0)
			incx += PLY_SIZE;
		else if (i == 1)
			incy += PLY_SIZE;
		else if (i == 2)
			incx -= PLY_SIZE;
	}
	return (false); 
	// check 
	
}
void	move(t_map *map, int mv)
{
	double	tmp;

	tmp = 100;
	if (mv == LEFT)
		map->rndr->turn_dir = -1;
	else if (mv == RIGHT)
		map->rndr->turn_dir = 1;
	if (mv == LEFT || mv == RIGHT)
		update_ang(map);
	if (mv == UP)
		map->rndr->walk_dir = 1;
	else if (mv == DOWN)
		map->rndr->walk_dir = -1;
	if (mv == DOWN || mv == UP)
	{
		if (inside_wall(map->rndr->pvec->x, map->rndr->pvec->y, map))
			return;
		else 
			update_pos(&map->rndr->pvec->x, &map->rndr->pvec->y, map);
	}
}





int	move_player(int key_code, t_map *map)
{

	/*if (inside_wall(map, key_code))*/
		/*return (1);*/
	
	
	move(map, key_code);
	if (key_code == EXIT)
		exit_free_if(true, NULL, NULL);
	mlx_clear_window(map->mlx->mlx, map->mlx->win);
	map = new_img(map);
	draw_map(map, 1);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);
	return (0);

}

void	rotate() {};
