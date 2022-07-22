/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:43:53 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 16:51:24 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

// add ray angle param 
t_map  *add_dist(t_map *map, double value, double ray_angle)
{
    size_t  i;

    
    // size_t i;
    // exit_free_if(!(new_arr = malloc(sizeof(*new_arr) * (map->rndr->wall->arr_len + 1))), "Error:\n\tmalloc failed\n", map);
    // exit_free_if(!(new_arr_angl = malloc(sizeof(*new_arr) * (map->rndr->wall->arr_len + 1))), "Error:\n\tmalloc failed\n", map);
 
    // i = 0;

    if (map->rndr->wall->len_arr == WIDTH)
        map->rndr->wall->len_arr = 0;
    i = map->rndr->wall->len_arr - 1;
    // while (i < map->rndr->wall->dist->len)
    // {
    //     new_arr[i] = map->rndr->wall->dist->arr[i];
    //     new_arr_angl[i] = map->rndr->wall->
    //     i++;
    // }
    // new_arr[i] = value;
    map->rndr->wall->arr_dist[i] = value;
    map->rndr->wall->arr_angl[i] = ray_angle;
    map->rndr->wall->len_arr += 1;
    // free(map->rndr->dist->arr);
    // map->rndr->wall->dist->arr = new_arr;
    return (map);
}


t_map   *add_ray_coor(t_map *map, double x, double y)
{

    // t_rays  *tmp;
    // size_t i;
    // if (map->rndr->wall->rays == NULL)
    // {
    //     exit_free_if(!(map->rndr->wall->rays = malloc(sizeof(t_rays))), "Error:\n\tmalloc failed\n", map);
    //     exit_free_if(!(map->rndr->wall->rays->coor = malloc(sizeof(t_vector))), "Error:\n\tmalloc failed\n", map);
    //     map->rndr->wall->rays->coor->x = x;
    //     map->rndr->wall->rays->coor->y = y;
    //     map->rndr->wall->rays->next = NULL;
    //     map->rndr->wall->rys_len = 1;
    // }
    // if (map->rndr->wall->rys_len > WIDTH)
    //     map->rndr->wall->rys_len = 0;
    // i = 0;
    // tmp = map->rndr->wall->rays;
    // while (tmp->next)
    //     tmp = tmp->next;
    // exit_free_if(!(tmp->next = malloc(sizeof(*tmp->next))), "Error:\n\tmalloc failed\n", map);
    // exit_free_if(!(tmp->next->coor = malloc(sizeof(*tmp->next->coor))), "Error:\n\tmalloc failed\n", map);
    // tmp->next->coor->x = x;
    // tmp->next->coor->y = y;

    // map->rndr->wall->rys_len += 1;
    // map->rndr->wall->rays->next = tmp->next;
    // map->rndr->wall->rays->next->next = NULL;
    if (map->rndr->wall->rys_len >= WIDTH)
        map->rndr->wall->rys_len = 0;
    map->rndr->wall->rays[map->rndr->wall->rys_len].x = x;
    map->rndr->wall->rays[map->rndr->wall->rys_len].y = y;
    map->rndr->wall->rys_len += 1;
    return (map);
}