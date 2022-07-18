/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:43:40 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/18 13:37:46 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

double  degtorad(double degree)
{
    return (degree * M_PI / 180);  
}

void    rasterize_vector(int x1, int y1, int x2, int y2, int c, t_map *map)
{
	(void)map;
	(void)x1;
	(void)y1;
	(void)x2;
	(void)y2;
	(void)c;
}
