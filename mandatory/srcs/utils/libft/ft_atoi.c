/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:23:23 by ren-nasr          #+#    #+#             */
/*   Updated: 2021/11/16 10:01:00 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Transforms string numbers into int.
 * 
 * Discards whitespace characters from the beginning of the string
 * 		- whitespace characeters are those for which isspace() is true
 * Recognizes the optional "+" or "-" sign
 * Parses the immediately following maximal string of base-10 digits
 * and converts it into a numerical value
 * Additional non-numerich characters are ignored
 */

static int	round_prevent(int sign)
{
	if (sign == -1)
		return (0);
	else if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	result;
	int					i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' || \
			str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - '0';
	}
	if (i > 19)
		return (round_prevent(sign));
	result *= sign;
	return (result);
}
