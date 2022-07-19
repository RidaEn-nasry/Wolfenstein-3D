/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:44:15 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/19 15:09:05 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <parser.h>
# include <mlx.h>

void	exit_free_if(int cond, char *msg, t_map *map);
t_map   *validate_map(char *map_file);


#endif
