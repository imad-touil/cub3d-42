/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:45:39 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/23 17:54:47 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_ceiling(t_cub *cub, char *line)
{
	if (cub->ceiling_set)
		error(cub, "Duplicate Ceilling Symbol");
	line++;
	if (*line != ' ' && *line != '\t')
		error(cub, "Invalid separator");
	line = skip_white_space(line);
	cub->ceiling->r = ft_atoi(line);
	line = skip_separator(cub, line);
	check_range(cub, cub->ceiling->r);
	cub->ceiling->g = ft_atoi(line);
	line = skip_separator(cub, line);
	check_range(cub, cub->ceiling->g);
	cub->ceiling->b = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line = skip_white_space(line);
	if (*line != '\0' && *line != '\n')
		error(cub, "Invalid Ceiling elements");
	check_range(cub, cub->ceiling->b);
	cub->ceiling_set = 1;
}
