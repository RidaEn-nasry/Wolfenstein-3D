/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intternary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:36:02 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:55:44 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    @description:
        - if condition is true, return first 
		argument, else return second argument
    @params:
        - int condition: condition to check
        - int first: first argument to return
        - int second: second argument to return
    @return:
        - first or second argument
*/

#include "libft.h"

int	ft_intternary(int condition, int first, int second)
{
	if (condition)
		return (first);
	return (second);
}
