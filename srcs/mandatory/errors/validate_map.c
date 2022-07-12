/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:59:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/11 13:30:57 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <errors.h>
#include <libft.h>

/** defualts:
 * if there's a missing value use a default one
 *
 *
 **/

/** checks:
 * if the map is not surronded by walls (one's) return an error.
 * if the map content is seperated by lines return an error
 * if the map content is not the last return an error 
 * if any of the sixth values is not starting or/and have a invalid identifier return an error
 * if there's not sixth values return an error, done
**/

void	validate_map( char *map_file ) {	
	char		*line;
	int		fd;

	// if file doesn't exist return an error
	exit_free_if( (fd = open(map_file, O_RDONLY)) == -1, "Error:\n\tinvalid map file", NULL);
	// if file extension is not .cub return an error
	exit_free_if((ft_strncmp(map_file + ft_strlen(map_file) - 4, ".cub", 4) != 0), "Error:\n\tinvalid map file. expected extension is .cub", NULL);
	// if the map contain less than 7 lines (map + 4textures + 2 rgb's ) return false
	exit_free_if(ft_filecount(map_file) < 7, "Error:\n\tMissing values in map file", NULL);
	// find all other identifiers 
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	int count = 1;
	while (line != NULL)
	{
		/*
		 *if (!isIdentifier(line))
		 *        printf("line %d is not an identifier\n", count);
		 */
		/*if (!isMap(line) )*/
		/*{*/
			/*printf("line with index: %d and content: %s is not a map\n", count, line);*/
		/*}*/
		if (isMap(line))
			printf("map in line %d\n", count);
		/*if (!ft_sisspace(line))*/
			/*printf("line is not a space\n");*/
			
		/*if (!isIdentifier(line) && !isMap(line) && !ft_sisspace(line))*/
			/*exit_free_if(true, "Error:\n\t invalid content in map file ", NULL);*/
		line = get_next_line(fd);
		count++;
	}
}


int main( void ) {
	char *map_file = "./map.cub";
	 
	validate_map(map_file);
	/*
	 *int fd = open(map_file, O_RDONLY);
	 *char *line = get_next_line(fd);
	 *while (line)
	 *{
	 *        printf("line: %s\n", line);
	 *        line = get_next_line(fd);
	 *}
	 */
	return (0);
} 
