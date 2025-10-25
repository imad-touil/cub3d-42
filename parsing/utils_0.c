/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:41:14 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/25 21:54:03 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_range(t_cub *cub, int nbr)
{
	if (nbr < 0 || nbr > 255)
		error(cub, "Enter Valid Range [0, 255]");
}

char	*skip_white_space(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

void	error(t_cub *cub, char *error)
{
	printf("%sError\n%s\n", RED, error);
	clean_up(cub);
	exit(EXIT_FAILURE);
}

char	*skip_separator(t_cub *cub, char *line)
{
	while (ft_isdigit(*line))
		line++;
	if (*line != ' ' && *line != '\t' && *line != ',' && *line != '\0')
		error(cub, "Error in color values");
	line = skip_white_space(line);
	if (*line == ',')
		line++;
	else 
		error(cub, "Enter A Valid Separator");
	line = skip_white_space(line);
	return (line);
}

void	clean_up(t_cub *cub)
{
	int	i;

	if (!cub)
		return ;
	free(cub->texture_no);
	free(cub->texture_so);
	free(cub->texture_we);
	free(cub->texture_ea);
	if (cub->map)
	{
		if (cub->map->grid)
		{
			i = -1;
			while (cub->map->grid[++i])
				free(cub->map->grid[i]);
			free(cub->map->grid);
		}
		free(cub->map);
	}
	free(cub->player);
}
