/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ternary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 07:58:10 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:44:32 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_ternary function imitates the ternary operator.
 *
 * @param {int} condition: the condition to be tested.
 * @param {void *} true_value: the value to be returned if condition is true.
 * @param {void *} false_value: the value to be returned if condition is false.
 * @return {void *}: the value to be returned.
 
*/

void	*ft_ternary(int condition, void *true_value, void *false_value)
{
	if (condition)
		return (true_value);
	else
		return (false_value);
}
