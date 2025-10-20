/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:55:31 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/20 21:47:25 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_map(t_cub *cub, char *file_name)
{
	int		fd;
	char	*line;

	cub->screen_height = 1000;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 1);
	line = get_next_line(fd);
	if (!line)
		return (printf("You Entered an empty file\n"), 0);
	return (0);
}
