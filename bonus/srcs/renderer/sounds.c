/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:55:11 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/27 09:45:00 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <renderer.h>

// play sound using afplay
void	play_sound(t_map *map)
{
	char	**arg;
	char	*cmd;

	cmd = "/usr/bin/afplay";
	exit_free_if(!(arg = malloc(sizeof(char *) * 3)),
		"Error:\n\tmalloc error", map, 1);
	arg[0] = ft_strdup(cmd);
	arg[1] = ft_strdup("./resources/sounds/sound2.mp3");
	arg[2] = NULL;
	if (map->rndr)
	{
		exit_free_if((map->rndr->music = fork())
			== -1, "Error:\n\tfork error", map, 1);
		if (map->rndr->music == 0)
			exit_free_if(execve(cmd, arg, map->env) == -1,
				"Error:\n\texecve error", map, 1);
	}
}
