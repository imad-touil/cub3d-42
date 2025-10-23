/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:53:35 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/23 20:37:35 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define WIN_W 1920
# define WIN_H 1080

# define RED "\e[31m"
# define RESET "\e[0m"

typedef struct s_cub
{
	int				screen_width;
	int				screen_height;
	int				resolution_set;
	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	int				has_no;
	int				has_so;
	int				has_we;
	int				has_ea;
	int				floor_set;
	int				ceiling_set;
	struct s_player	*player;
	struct s_color	*floor;
	struct s_color	*ceiling;
	struct smap		*map;
}					t_cub;

typedef struct s_player
{
	int		x;
	int		y;
	char	direction;
}			t_player;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_map
{
	int		width;
	int		height;
	char	*grid;
}			t_map;

int		parse_map(t_cub *cub, char *file_name);
char	*skip_white_space(char *str);
void	error(t_cub *cub, char *error);
void	parse_texture(t_cub *cub, char *line);
void	check_range(t_cub *cub, int nbr);
char	*skip_separator(t_cub *cub, char *line);
void	parse_ceiling(t_cub *cub, char *line);
void	parse_floor(t_cub *cub, char *line);
void	clean_up(t_cub *cub);

#endif