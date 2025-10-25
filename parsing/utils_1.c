/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 17:53:12 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/25 22:25:28 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_split(char **grid)
{
	int	i;

	i = -1;
	while (grid[++i])
		free(grid[i]);
	free(grid);
}

static int	norm_helper(char **grid, int x, int y, int height)
{
	if (y == 0 || y == height - 1 || x == 0
		|| grid[y][x + 1] == '\0')
		return (0);
	if (x >= (int)ft_strlen(grid[y - 1]) || grid[y - 1][x] == ' '
		|| x >= (int)ft_strlen(grid[y + 1]) || grid[y + 1][x] == ' ')
		return (0);
	if (grid[y][x - 1] == ' ' || grid[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	is_map_closed(t_cub *cub, char **grid)
{
	int		y;
	int		x;
	char	c;

	y = -1;
	while (++y < cub->map->height && grid[y])
	{
		x = -1;
		while (grid[y][++x])
		{
			c = grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0')
			{
				if (!norm_helper(grid, x, y, cub->map->height))
					return (0);
			}
		}
	}
	return (1);
}

void	find_player(t_cub *cub)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	while (cub->map->grid[++y])
	{
		x = -1;
		while (cub->map->grid[y][++x])
		{
			c = cub->map->grid[y][x];
			if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
			{
				cub->player->x = x;
				cub->player->y = y;
				cub->player->direction = c;
				return ;
			}
		}
	}
}

char	*join_line(char *map_data, char *line)
{
	char	*tmp;
	char	*joined;

	joined = ft_strjoin(map_data, line);
	tmp = joined;
	free(map_data);
	return (tmp);
}
