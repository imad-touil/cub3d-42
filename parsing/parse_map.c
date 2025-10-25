/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:10:48 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/25 21:51:31 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_player(t_cub *cub, char **grid)
{
	int	i;
	int	j;
	int	nbr;

	nbr = 0;
	i = -1;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (grid[i][j] == 'N' || grid[i][j] == 'S'
				|| grid[i][j] == 'W' || grid[i][j] == 'E')
				nbr++;
			else if (grid[i][j] != 'N' && grid[i][j] != 'S'
				&& grid[i][j] != 'W' && grid[i][j] != 'E'
				&& grid[i][j] != '1' && grid[i][j] != '0'
				&& grid[i][j] != ' ')
				error(cub, "Invalid character in map!");
		}
	}
	return (nbr);
}

static int	max_width(char **grid)
{
	int		i;
	size_t	max;

	i = 0;
	max = ft_strlen(grid[0]);
	while (grid[++i])
	{
		if (ft_strlen(grid[i]) > max)
			max = ft_strlen(grid[i]);
	}
	return (max);
}

static void	fill_grid(t_cub *cub, char *map_data)
{
	char	**lines;
	int		i;

	lines = ft_split(map_data, '\n');
	cub->map->height = 0;
	cub->map->width = 0;
	while (lines[cub->map->height])
		cub->map->height++;
	cub->map->grid = malloc(sizeof(char *) *(cub->map->height + 1));
	if (!cub->map->grid)
		error(cub, "Allocation Failed!");
	i = -1;
	while (lines[++i])
	{
		cub->map->grid[i] = ft_strdup(lines[i]);
		if (!cub->map->grid[i])
			error(cub, "Allocation Failed");
	}
	cub->map->grid[i] = NULL;
	cub->map->width = max_width(cub->map->grid);
	free_split(lines);
}

void	parse_map(t_cub *cub, char *map_data)
{
	int		player_nbr;
	int		i;

	fill_grid(cub, map_data);
	i = -1;
	while (cub->map->grid[++i])
		printf("%s\n", cub->map->grid[i]);
	player_nbr = count_player(cub, cub->map->grid);
	if (player_nbr != 1)
		error(cub, "Map must contain exactly one player!");
	if (is_map_closed(cub, cub->map->grid))
		find_player(cub);
	else
		error(cub, "Map Open!");
}
