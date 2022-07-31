/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:43:52 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 23:08:48 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>
#include <parser.h>

void	free_txtr(t_map *map)
{
	ft_sfree(map->txtr->north);
	ft_sfree(map->txtr->south);
	ft_sfree(map->txtr->west);
	ft_sfree(map->txtr->east);
	ft_sfree(map->txtr);
}

void	free_rndr(t_map *map)
{
	ft_sfree(map->rndr->pvec);
	ft_sfree(map->rndr->wall);
	ft_sfree(map->rndr->proj);
}

void	exit_free_if( int cond, char *msg, t_map *map, int code)
{
	if (cond)
	{
		if (map)
		{
			if (map->map)
				ft_doubfree((void **)map->map, 0);
			ft_sfree(map->clr);
			free_txtr(map);
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
