/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:41:15 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/23 17:55:43 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	norm_helper(t_cub *cub, char **texture, char *line, int *flag)
{
	int	fd;
	int	len;

	if (*flag)
		error(cub, "Duplicate Texture Symbol");
	line += 2;
	if (*line != ' ' && *line != '\t')
		error(cub, "Invalid texture path!");
	line = skip_white_space(line);
	line = ft_strtrim(line, "\n");
	len = ft_strlen(line);
	if (len <= 4 || ft_strncmp(".xpm", line + len - 4, 4))
		error(cub, "wrong texture file");
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
		norm_helper(cub, &cub->texture_no, line, &cub->has_no);
	else if (!ft_strncmp(line, "SO", 2))
		norm_helper(cub, &cub->texture_so, line, &cub->has_so);
	else if (!ft_strncmp(line, "WE", 2))
		norm_helper(cub, &cub->texture_we, line, &cub->has_we);
	else if (!ft_strncmp(line, "EA", 2))
		norm_helper(cub, &cub->texture_ea, line, &cub->has_ea);
}
