/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:09:17 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/19 18:41:19 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>


void	move(t_map *map, int mv)
{
	if (mv == LEFT)
		map->rndr->turn_dir = 1;
	else if (mv == RIGHT)
		map->rndr->turn_dir = -1;
	else if (mv == UP)
		map->rndr->walk_dir = 1;
	else if (mv == DOWN)
		map->rndr->walk_dir = -1;
}

bool	inside_wall(t_map *map, int key_code)
{

	/*double	x; 	*/
	/*double	y;*/

	/*if (key_code == RIGHT || key_code == DOWN)*/
	/*{*/
		/*x = map->rndr->pvec->x + PLY_SIZE / 2;*/
		/*y = map->rndr->pvec->y + PLY_SIZE / 2;*/
	/*}*/
	/*else {*/
		/*x = map->rndr->pvec->x;*/
		/*y = map->rndr->pvec->y;*/
	/*}*/
	move(map, key_code);
	/*int index_x = x / CELL_SIZE;*/
	/*int index_y = y / CELL_SIZE;*/

	/*printf("index_x: %d\nindex_y: %d\n", index_x, index_y);*/
	/*if (map->map[index_y][index_x] == '1')*/
		/*return (true);*/
	/*else if (map->map[index_y][index_x] == '0')*/
		/*return (false);*/
	return (false); 
	// check 
	
}
int	move_player(int key_code, t_map *map)
{
	(void)key_code;

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
