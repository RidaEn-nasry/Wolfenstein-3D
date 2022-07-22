/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:43:52 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 15:56:43 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>
#include <parser.h>

void	exit_free_if( int cond, char *msg, t_map *map)
{
	// t_rays	*tmp;
	if (cond) {

		if (map){
		// free stuff here
			// ft_doubfree(map->map, ft_2darr_len((const char **)map->map));
			// ft_sfree(map->clr);
			// ft_sfree(map->txtr);
			
			// // mlx stuff here
			// mlx_destroy_image(map->mlx->mlx, map->mlx->img);
			// ft_sfree(map->mlx->img_data);
			// ft_sfree(map->mlx->img);
			// ft_sfree(map->mlx->win);
			// ft_sfree(map->mlx->mlx);
			// ft_sfree(map->mlx);
			
			// // rdnr stuff here
			// ft_sfree(map->rndr->pvec);
			// ft_sfree(map->rndr->wall);
			// ft_sfree(map->rndr->wall->step);
			// ft_doubfree(map->rndr->wall->dist->arr, map->rndr->wall->dist->len);
			// ft_sfree(map->rndr->wall->dist);
		
			// tmp = map->rndr->wall->rays;
			// while (tmp->next)
			// {
			// 	ft_doubfree(map->rndr->wall->rays->coor, map->rndr->wall->rays->len)
			// 	ft_sfree(tmp->rays);
			// 	tmp = tmp->next;
			// }	
			
			mlx_destroy_window(map->mlx->mlx, map->mlx->win);
		}
		if (msg)	
			ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
	}
}
