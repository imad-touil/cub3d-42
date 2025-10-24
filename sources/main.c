/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:54:12 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/24 16:25:35 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->texture_no = NULL;
	cub->texture_so = NULL;
	cub->texture_we = NULL;
	cub->texture_ea = NULL;
	cub->resolution_set = 0;
	cub->ceiling = NULL;
	cub->floor = NULL;
	cub->has_no = 0;
	cub->has_so = 0;
	cub->has_we = 0;
	cub->has_ea = 0;
	cub->screen_height = WIN_H;
	cub->screen_width = WIN_W;
	cub->ceiling_set = 0;
	cub->floor_set = 0;
	cub->ceiling = malloc(sizeof(t_color));
	if (!cub->ceiling)
		error(cub, "Error\nMemory allocation failed");
	cub->floor = malloc(sizeof(t_color));
	if (!cub->floor)
		error(cub, "Error\nMemory allocation failed");
}

int	handel_key(int key_code, void *param)
{
	param = (char *)param;
	if (key_code == 53)
	{
		printf("thala!\n");
		exit(0);
	}
	return (0);
}

void	ll(void)
{
	system("leaks -q cub3d");
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_cub	*cub;

	atexit(ll);
	if (ac != 2)
		return (printf("%sError\nEnter One Arg!\n", RED), 1);
	else if ((ft_strlen(av[1]) <= 4)
		|| (ft_strncmp(".cub", av[1] + ft_strlen(av[1]) - 4, 4)))
		return (printf("%sError\nEnter .cub file extension\n", RED), 1);
	cub = malloc(sizeof(t_cub));
	if (!cub)
		return (perror("Cub3D"), 1);
	init_cub(cub);
	if (parse_map(cub, av[1]))
		return (0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, cub->screen_width, cub->screen_height, "Cub3D");
	mlx_key_hook(win, handel_key, NULL);
	mlx_loop(mlx);
	clean_up(cub);
	return (0);
}
