/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:24:09 by mkarim            #+#    #+#             */
/*   Updated: 2022/07/27 09:53:08 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

void	move(t_map *map, int mv)
{
	if (mv == LEFT)
		map->rndr->turn_dir = -1;
	else if (mv == RIGHT)
		map->rndr->turn_dir = 1;
	if (mv == LEFT || mv == RIGHT)
		update_ang(map);
	if (mv == KEY_W)
		map->rndr->walk_dir = 1;
	else if (mv == KEY_S)
		map->rndr->walk_dir = -1;
	if (mv == KEY_A)
		move_left(map);
	if (mv == KEY_D)
		move_right(map);
	if (mv == KEY_S || mv == KEY_W)
	{
		if (inside_wall(map->rndr->pvec->x, map->rndr->pvec->y, map))
			return ;
		else
			update_pos(&map->rndr->pvec->x, &map->rndr->pvec->y, map);
	}
}

int	move_player(int key_code, t_map *map)
{
	move(map, key_code);
	if (key_code == EXIT)
		exit_free_if(true, NULL, map, 0);
	mlx_clear_window(map->mlx->mlx, map->mlx->win);
	map = new_img(map);
	draw_map(map, 1);
	mlx_put_image_to_window(map->mlx->mlx, map->mlx->win, map->mlx->img, 0, 0);
	return (0);
}
