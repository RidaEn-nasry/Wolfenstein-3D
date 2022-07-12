/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:17:08 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/12 15:44:21 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

/**
 * @brief Check if the line is an identifier (path to texture or color value)
 * @howto: checking if the 1 or 2 first characters a valid identifier 
 						* (F or C or NO or SO or WE or EA)) 
 * @param line: char * to the line to check
 * @return true 
 * @return false 
 */

bool	is_identifier(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if ((line[i] == 'F') || (line[i] == 'C') || \
			(line[i] == 'N' && line[i + 1] == 'O') || \
			(line[i] == 'S' && line[i + 1] == 'O') || \
			(line[i] == 'W' && line[i + 1] == 'E') || \
			(line[i] == 'E' && line[i + 1] == 'A'))
		return (true);
	return (false);
}

bool	is_map(char *line)
{
	size_t	i;

	i = 0;
	printf("len: %lu\n", ft_strlen(line));
	while (i < ft_strlen(line) - 1)
	{
		while (ft_isspace(line[i]))
			i++;
		if (line[i] != '0' && line[i] != '1' && line[i] != 'S' && \
		line[i] != 'E' && line[i] != 'W' && line[i] != 'N')
			return (false);
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
