/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:41:15 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/23 21:35:27 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	norm_helper(t_cub *cub, char **texture, char *line, int *flag)
{
	int		fd;
	int		len;
	char	*tmp;

	if (*flag)
		error(cub, "Duplicate Texture Symbol");
	tmp = line;
	tmp += 2;
	if (*tmp != ' ' && *tmp != '\t')
		error(cub, "Invalid texture path!");
	tmp = skip_white_space(tmp);
	tmp = ft_strtrim(tmp, "\n");
	len = ft_strlen(tmp);
	if (len <= 4 || ft_strncmp(".xpm", tmp + len - 4, 4))
		error(cub, "wrong texture file");
	fd = open(tmp, O_RDONLY);
	if (fd == -1)
		error(cub, "Error : wrong texture path!");
	close(fd);
	*texture = ft_strdup(tmp);
	*flag = 1;
	free(tmp);
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
