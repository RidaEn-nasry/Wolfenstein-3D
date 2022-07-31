/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:35:51 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 23:09:07 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>

bool	is_plyr(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

bool	is_txtr(char c)
{
	if (c == 'N' || c == 'O' || c == 'S' || c == 'W' \
		|| c == 'W' || c == 'E' || c == 'A')
		return (true);
	return (false);
}

char	*check_line(char *line)
{
	char	*trim;
	size_t	len;
	int		count;

	count = 0;
	if (ft_isspace(line[0]))
	{
		trim = ft_strtrim(line, " ");
		count += 1;
	}
	if (count == 0)
		trim = line;
	len = ft_strlen(trim);
	if (trim[len - 1] == '\n')
	{
		trim[len - 1] = '\0';
		count += 1;
	}
	if (count == 2)
		ft_sfree(trim);
	return (trim);
}

size_t	get_max(char **map)
{
	size_t	max;
	int		i;
	size_t	len;

	i = 1;
	max = ft_strlen(map[0]);
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

bool	check_map(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	if (!all_ones(map[0]) \
	|| !all_ones(map[ft_2darr_len((const char **)map) - 1]))
		return (false);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_plyr(map[i][j]))
				count++;
			if (!valid(map, i, j))
				return (false);
			j++;
		}
		i++;
	}
	exit_free_if(count != 1, \
		"Error:\n\tThere must be exactly one player", NULL, 1);
	return (true);
}
