/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:17:08 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/11 12:49:31 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

bool	isIdentifier(char *line) {
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if ((line[i] == 'F') || (line[i] == 'C') ||\
			(line[i] == 'N' && line[i + 1] == 'O') || \
			(line[i] == 'S' && line[i + 1] == 'O') ||\
			(line[i]  == 'W' && line[i + 1] == 'E') ||\
			(line[i] == 'E' && line[i + 1] == 'A'))
			
		return (true);
	return (false);
}

bool	isMap(char *line) {
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	printf("length of line: %zu\n", ft_strlen(line));	
	while (i < ft_strlen(line) - 1){
		if (line[i] != '0' && line[i] != '1' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != 'N' && !ft_isspace(line[i]))
		/*
		 *if (line[i] != '0' && line[i] != '1' && !ft_isspace(line[i]))
		 *{
		 *        printf("this char: %i is not a zero nor a one\n", line[i]);
		 */
			return (false);
		
		/*}*/
		i++;
	}
	return (true);
}

/*
 *int main ( void ) {
 *
 *        char *content = "0101010101";
 *        char *content 2
 *        if (!isMap(content))
 *                printf("is a map\n");
 *        return 0;
 *
 *}
 */


