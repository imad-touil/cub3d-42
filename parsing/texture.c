/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:41:15 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/22 15:29:24 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	norm_helper(t_cub *cub, char **texture, char *line, int *flag)
{
	int	fd;

	if (*flag)
		error(cub, "Error: Duplicate Texture Symbol");
	line += 2;
	if (*line != ' ' && *line != '\t')
		error(cub, "Invalid texture path!");
	line = skip_white_space(line);
	line = ft_strtrim(line, "\n");
	fd = open(line, O_RDONLY);
	if (fd == -1)
		error(cub, "Error : wrong texture path!");
	close(fd);
	*texture = ft_strdup(line);
	*flag = 1;
}

void	parse_texture(t_cub *cub, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		norm_helper(cub, &cub->texture_no, line, &cub->has_no);
		printf("%s\n", cub->texture_no);
	}
	else if (!ft_strncmp(line, "SO", 2))
	{
		norm_helper(cub, &cub->texture_so, line, &cub->has_so);
		printf("%s\n", cub->texture_so);
	}
	else if (!ft_strncmp(line, "WE", 2))
	{
		norm_helper(cub, &cub->texture_we, line, &cub->has_we);
		printf("%s\n", cub->texture_we);
	}
	else if (!ft_strncmp(line, "EA", 2))
	{
		norm_helper(cub, &cub->texture_ea, line, &cub->has_ea);
		printf("%s\n", cub->texture_ea);
	}
}
