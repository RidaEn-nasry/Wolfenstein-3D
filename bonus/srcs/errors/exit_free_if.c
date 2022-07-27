/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:43:52 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/27 09:43:49 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <renderer.h>

void	free_rndr(t_map *map)
{
	ft_sfree(map->rndr->pvec);
	ft_sfree(map->rndr->wall);
	ft_sfree(map->rndr->proj);
}

void	exit_free_if( int cond, char *msg, t_map *map, int code )
{
	if (cond)
	{
		if (map)
		{
			if (map->rndr)
				kill(map->rndr->music, SIGKILL);
			if (map->map)
				ft_doubfree((void **)map->map, \
					ft_2darr_len((const char **)map->map));
			ft_sfree(map->clr);
			ft_sfree(map->txtr);
			if (map->rndr)
				free_rndr(map);
			if (map->mlx)
				mlx_destroy_window(map->mlx->mlx, map->mlx->win);
		}
		if (msg)
			ft_putendl_fd(msg, 2);
		exit(code);
	}
}
