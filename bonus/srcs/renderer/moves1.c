/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:09:17 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 18:08:00 by mkarim           ###   ########.fr       */
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
		update_ang(map, &map->rndr->rot_angl);
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

int	mouse_hook(int x, int y, t_map *map)
{
	static int	last_x;

	(void)y;
	if (x > WIDTH || x < 0)
		return (0);
	map->rndr->turn_spd = get_turn_spd(last_x, x);
	x = get_mouse_x(map);
	if (x - last_x > 0)
		move(map, RIGHT);
	else if (x - last_x < 0)
		move(map, LEFT);
	map->rndr->turn_spd = degtorad(10);
	update_screen(map);
	last_x = x;
	return (0);
}
