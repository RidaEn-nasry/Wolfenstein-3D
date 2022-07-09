/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:43:52 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/09 21:10:32 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>
#include <parser.h>
void	exit_free_if( int cond, char *msg, t_map *map)
{
	if (cond) {

		if (map){
				// free stuff here
		}
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
	}
}
