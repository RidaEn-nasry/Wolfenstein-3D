/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:17:08 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/09 21:20:53 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

bool	isIdentifier(char *line) {
	if ((line[0] == 'N' && line[1] == 'O') || \
			(line[0] == 'S' && line[1] == 'O') ||\
			(line[0]  == 'W' && line[1] == 'E') ||\
			(line[0] == 'E' && line[1] == 'A'))
		return (true);
	return (false);
}

