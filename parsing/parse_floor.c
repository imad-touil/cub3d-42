/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_floor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:58:58 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/25 12:23:00 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_floor(t_cub *cub, char *line)
{
	if (cub->floor_set)
		error(cub, "Duplicate Floor Symbol");
	line++;
	if (*line != ' ' && *line != '\t')
		error(cub, "Invalid separator");
	line = skip_white_space(line);
	cub->floor->r = ft_atoi(line);
	line = skip_separator(cub, line);
	check_range(cub, cub->floor->r);
	cub->floor->g = ft_atoi(line);
	line = skip_separator(cub, line);
	check_range(cub, cub->floor->g);
	cub->floor->b = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = skip_white_space(line);
	if (*line != '\0' && *line != '\n')
		error(cub, "Invalid floor elements");
	check_range(cub, cub->floor->b);
	cub->floor_set = 1;
}
