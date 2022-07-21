/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:43:53 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/21 23:59:11 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>


t_darr  *add_dist(t_map *map, double value)
{
    double  *new_arr;
    size_t i;
    exit_free_if(!(new_arr = malloc(sizeof(*new_arr) * (map->rndr->dist->i + 1))), "Error:\n\tmalloc failed\n", map);
    i = 0;
    if (i == 0)
    {
        new_arr[i] = value;
        i++;
    }
    while (i <= map->rndr->dist->i)
    {
        new_arr[i] = map->rndr->dist->arr[i];
        i++;
    }
    new_arr[i] = value;
    // free(map->rndr->dist->arr);
    map->rndr->dist->arr = new_arr;
    return (map->rndr->dist);
}