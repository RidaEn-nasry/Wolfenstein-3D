/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:12:10 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/11/15 14:03:30 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Checks if given character is alpha-numerical */

int	ft_isalnum(int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123) || (c > 47 && c < 58));
}