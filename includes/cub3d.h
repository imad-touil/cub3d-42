/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:53:35 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/20 15:55:32 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "mlx.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define WIN_W 1920
#define WIN_H 1080

typedef struct s_cub
{
	int				width;
	int				height;
	char			*grid;
	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	struct s_player	*player;
	struct s_color	*floor;
	struct s_color	*ceiling;
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

int	parse_map(char *file_name);

#endif