/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitif.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:55:54 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/13 15:31:46 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* exitif.c implementation :
	- exit with error message if condition is true	
	- return 0 if condition is false
*/

#include "libft.h"

int	exitif(int condition, char *message)
{
	if (condition)
	{
		ft_putendl_fd(message, 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
