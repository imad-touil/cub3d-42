/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:10:48 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/24 23:46:51 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_map_line(char *line)
{
	int	has;

	has = 0;
	while (*line)
	{
		if (*line == '1' || *line == '0'
			|| *line == 'N' || *line == 'S'
			|| *line == 'E' || *line == 'W')
			has = 1;
		else if (*line != ' ' && *line != '\t')
			return (0);
		line++;
	}
	return (has);
}

void	parse_map(t_cub *cub, char *line)
{
	if (!cub->ceiling_set || !cub->floor || !cub->has_we
		|| !cub->has_no || !cub->has_so || !cub->has_ea)
		error(cub, "Missing map elements");
	printf("%s\n", line);
}