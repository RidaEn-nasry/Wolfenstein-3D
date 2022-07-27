/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lineinsert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 09:58:06 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/26 01:55:09 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	@description:
		- insert (overwrite) a section of a line with a new content.
		- the section is defined by the start and end indexes
	@param:
		- char *line: the line to modify
		- char *new: the new content
		- size_t start: the start index of the section
		- size_t end: the end index of the section
	@return:
		- char *: the modified line
		- NULL: if the line or content is NULL
		- NULL: if the start index is greater than the end index
		- NULL: if the start index or the end 
		index is greater than the length of the line
		- char * old line: if content is empty
	@Complexity:
		- oh god, i don't know...
	@example:
		- char *line = "Hello World";
		- ft_lineinsert(line, "Bonjour", 0, 5);
		- line = "Bonjour World";
	@IMPORTANT:
		- The function expects char *line && 
		char *content to be dynamically allocated using malloc.
		
*/

#include "libft.h"

char	*ft_lineinsert(char *line, char *content, size_t start, size_t end)
{
	char	*new_line;

	if (!line || !content)
		return (NULL);
	if (start > end)
		return (NULL);
	if (start > ft_strlen(line) || end > ft_strlen(line))
		return (NULL);
	if (ft_strlen(content) == 0)
		return (line);
	new_line = ft_substr(line, 0, start);
	if (!new_line)
		return (NULL);
	new_line = ft_strjoin(new_line, content);
	if (!new_line)
		return (NULL);
	new_line = ft_strjoin(new_line, ft_substr(line, end, ft_strlen(line)));
	if (!new_line)
		return (NULL);
	ft_sfree(line);
	ft_sfree(content);
	line = new_line;
	return (line);
}
