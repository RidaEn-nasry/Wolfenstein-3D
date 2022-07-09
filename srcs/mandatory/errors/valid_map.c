/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:59:26 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/07/09 21:26:40 by ren-nasr         ###   ########.fr       */
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

bool	valid_map( char *map_file ) {
	
	char		*line;
	int		fd;

	// if file doesn't exist return an error
	exit_free_if( (fd = open(map_file, O_RDONLY)) == -1, "Error:\n\tinvalid map file", NULL);
	// if file extension is not .cub return an error
	exit_free_if((ft_strncmp(map_file + ft_strlen(map_file) - 4, ".cub", 4) != 0), "Error:\n\tinvalid map file. expected extension is .cub", NULL);
	// if the map contain less than 7 lines (map + 4textures + 2 rgb's ) return false
	exit_free_if(ft_filecount(map_file) < 7, "Error:\n\tMissing values in map file", NULL);
	return (true);
}

/*
 *
 *int main( void ) {
 *        char *map_file = "./map.cub";
 *         
 *        valid_map(map_file);
 *        return (0);
 *} 
 */
