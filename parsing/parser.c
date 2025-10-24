/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:55:31 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/24 23:55:48 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parser(t_cub *cub, char *file_name)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error(cub, "Can't Open file");
	line = get_next_line(fd);
	if (!line)
		error(cub, "You Entered an empty file");
	while (line)
	{
		tmp = line;
		
		tmp = skip_white_space(tmp);
		if (*tmp == 'C')
			parse_ceiling(cub, tmp);
		else if (*tmp == 'F')
			parse_floor(cub, tmp);
		else if (!ft_strncmp(tmp, "NO", 2) || !ft_strncmp(tmp, "SO", 2)
			|| !ft_strncmp(tmp, "WE", 2) || !ft_strncmp(tmp, "EA", 2))
			parse_texture(cub, tmp);
		else if (is_map_line(tmp))
			parse_map(cub, tmp);
		else
			error(cub, "Invalide Line!");
		free(line);
		line = get_next_line(fd);
	}
	return (close(fd), 0);
}
