/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:55:31 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/21 17:08:53 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*skip_white_space(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

static void	error(t_cub *cub, char *error)
{
	printf("%s\n", error);
	// clean_up(cub); TODO
	cub->screen_height = 1337; // just for compiling flags;
	exit(EXIT_FAILURE);
}

static int	parse_resolution(t_cub *cub, char *line)
{
	if (cub->resolution_set)
		error(cub, "Error: Dublicated Resolution!");
	line++;
	line = skip_white_space(line);
	cub->screen_width = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = skip_white_space(line);
	cub->screen_height = ft_atoi(line);
	if (cub->screen_height <= 0 || cub->screen_width <= 0)
		error(cub, "Error: resolution values must be positive!");
	cub->resolution_set = 1;
	return (0);
}

int	parse_map(t_cub *cub, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (perror("Error opening file"), 1);
	line = get_next_line(fd);
	if (!line)
		return (printf("You Entered an empty file\n"), 0);
	while (line)
	{
		line = skip_white_space(line);
		if (*line == 'R')
			parse_resolution(cub, line);
		// else if (!ft_strncmp(line, "SO", 2))
		line = get_next_line(fd);
	}
	return (0);
}
