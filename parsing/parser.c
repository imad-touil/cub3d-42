/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:55:31 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/25 22:54:52 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_map_line(char *line)
{
	if (*line == '1' || *line == '0'
		|| *line == 'N' || *line == 'S'
		|| *line == 'W' || *line == 'E')
		return (1);
	return (0);
}

static void	append_map_lines(char **map_data, int fd, char *line)
{
	while (line)
	{
		*map_data = join_line(*map_data, line);
		free(line);
		line = get_next_line(fd);
	}
}

static void	norm_helper(t_cub *cub, char **map_data, int fd, char *line)
{
	char	*tmp;

	while (line)
	{
		tmp = skip_white_space(line);
		if (*tmp == 'C')
			parse_ceiling(cub, tmp);
		else if (*tmp == 'F')
			parse_floor(cub, tmp);
		else if (!ft_strncmp(tmp, "NO", 2) || !ft_strncmp(tmp, "SO", 2)
			|| !ft_strncmp(tmp, "WE", 2) || !ft_strncmp(tmp, "EA", 2))
			parse_texture(cub, tmp);
		else if (is_map_line(tmp))
		{
			if (!cub->ceiling_set || !cub->floor_set || !cub->has_we
				|| !cub->has_no || !cub->has_so || !cub->has_ea)
				error(cub, "Missing map elements");
			append_map_lines(map_data, fd, line);
			break ;
		}
		else if (*tmp != '\n')
			error(cub, "Invalid Line");
		free(line);
		line = get_next_line(fd);
	}
}

int	parser(t_cub *cub, char *file_name)
{
	int		fd;
	char	*line;
	char	*map_data;

	map_data = ft_strdup("");
	if (!map_data)
		error(cub, "Memory allocation failed");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error(cub, "Can't open file");
	line = get_next_line(fd);
	if (!line)
		error(cub, "You entered an empty file");
	norm_helper(cub, &map_data, fd, line);
	if (!*map_data)
		error(cub, "Map missing");
	parse_map(cub, map_data);
	free(map_data);
	return (close(fd), 0);
}
