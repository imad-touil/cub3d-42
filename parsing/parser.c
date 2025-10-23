/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:55:31 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/23 17:58:06 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_resolution(t_cub *cub, char *line)
{
	if (cub->resolution_set)
		error(cub, "Dublicated Resolution!");
	line++;
	if (*line != ' ' && *line != '\t')
		error(cub, " Resolution identifier misalignment");
	line = skip_white_space(line);
	cub->screen_width = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	if (*line != ' ' && *line != '\t')
		error(cub, "Invalid Resolution elements");
	line = skip_white_space(line);
	cub->screen_height = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = skip_white_space(line);
	if (*line != '\0' && *line != '\n')
		error(cub, "Invalid Resolution elements");
	if (cub->screen_height <= 0 || cub->screen_width <= 0)
		error(cub, "resolution values must be positive!");
	cub->resolution_set = 1;
	return (0);
}

int	parse_map(t_cub *cub, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error(cub, "Can't Open file");
	line = get_next_line(fd);
	if (!line)
		error(cub, "You Entered an empty file");
	while (line)
	{
		line = skip_white_space(line);
		if (*line == 'R')
			parse_resolution(cub, line);
		else if (*line == 'C')
			parse_ceiling(cub, line);
		else if (*line == 'F')
			parse_floor(cub, line);
		else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2)
			|| !ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
			parse_texture(cub, line);
		line = get_next_line(fd);
		// free(line);
	}
	return (0);
}
