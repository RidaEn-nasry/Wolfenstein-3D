/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 00:26:13 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/29 22:35:05 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <errors.h>

void	skip_spcs(char **map, int *i)
{
	int	index;

	index = *i;
	while (map[index])
	{
		if (!ft_isempty(map[index]) && is_map(map[index]))
			break ;
		index += 1;
	}
	*i = index;
}

char	**get_new_map(char **map)
{
	size_t	maxlen;
	int		i;
	char	**new;

	i = 0;
	skip_spcs(map, &i);
	maxlen = get_max(map);
	new = ft_doubdup(&map[i]);
	ft_doubfree((void **)map, 0);
	i = 0;
	while (new[i])
	{
		if (is_map(new[i]))
		{
			if (ft_strlen(new[i]) < maxlen)
				new[i] = add_spaces(new[i], maxlen);
		}
		else
		{
			ft_sfree(new[i]);
			new[i] = NULL;
		}
		i++;
	}
	return (new);
}

bool	all_ones(char *line)
{
	char	*trim;
	int		i;

	i = 0;
	trim = ft_strtrim(line, " ");
	if (trim[ft_strlen(trim) - 1] == '\n')
		trim[ft_strlen(trim) - 1] = '\0';
	while (trim[i] != '\0')
	{
		if (trim[i] != '1')
		{
			ft_sfree(trim);
			return (false);
		}
		i++;
	}
	ft_sfree(trim);
	return (true);
}

bool	valid(char **line, int i, int j)
{
	if (line[i + 1] && line[i][j + 1])
	{
		if ((line[i][j] == '0' && line[i][j + 1] == ' ') || \
			(line[i][j] == ' ' && line[i][j + 1] == '0') || \
			(line[i][j] == ' ' && line[i + 1][j] == '0') || \
			(line[i][j] == '0' && line[i + 1][j] == ' ') || \
			!check_plyr(line, i, j))
			return (false);
	}
	return (true);
}

char	*add_spaces(char *line, size_t maxlen)
{
	size_t	len;
	char	*new;

	len = ft_strlen(line);
	exit_free_if(!(new = malloc(sizeof(char ) * maxlen + 1)), \
		"Error:\n\tmalloc failed", NULL, 1);
	ft_strlcpy(new, line, maxlen);
	while (len < maxlen)
	{
		new[len] = ' ';
		len++;
	}
	new[len] = '\0';
	ft_sfree(line);
	return (new);
}
