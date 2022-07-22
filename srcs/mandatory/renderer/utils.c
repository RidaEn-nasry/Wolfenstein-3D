/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:43:53 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/22 01:15:45 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>


t_darr  *add_dist(t_map *map, double value)
{
    double  *new_arr;
    size_t i;
    exit_free_if(!(new_arr = malloc(sizeof(*new_arr) * (map->rndr->dist->len + 1))), "Error:\n\tmalloc failed\n", map);
    i = 0;

    
    while (i < map->rndr->dist->len)
    {
        new_arr[i] = map->rndr->dist->arr[i];
        i++;
    }
    new_arr[i] = value;
    map->rndr->dist->len += 1;
    // free(map->rndr->dist->arr);
    map->rndr->dist->arr = new_arr;
    return (map->rndr->dist);
}