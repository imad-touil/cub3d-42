/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:55:31 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/23 22:05:27 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	parse_resolution(t_cub *cub, char *line)
{
	char	*tmp;

	if (cub->resolution_set)
		error(cub, "Dublicated Resolution!");
	tmp = line + 1;
	if (*tmp != ' ' && *tmp != '\t')
		error(cub, " Resolution identifier misalignment");
	tmp = skip_white_space(tmp);
	cub->screen_width = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		tmp++;
	if (*tmp != ' ' && *tmp != '\t')
		error(cub, "Invalid Resolution elements");
	tmp = skip_white_space(tmp);
	cub->screen_height = ft_atoi(tmp);
	while (ft_isdigit(*tmp))
		tmp++;
	tmp = skip_white_space(tmp);
	if (*tmp != '\0' && *tmp != '\n')
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
		if (*tmp == 'R')
			parse_resolution(cub, tmp);
		else if (*tmp == 'C')
			parse_ceiling(cub, tmp);
		else if (*tmp == 'F')
			parse_floor(cub, tmp);
		else if (!ft_strncmp(tmp, "NO", 2) || !ft_strncmp(tmp, "SO", 2)
			|| !ft_strncmp(tmp, "WE", 2) || !ft_strncmp(tmp, "EA", 2))
			parse_texture(cub, tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
