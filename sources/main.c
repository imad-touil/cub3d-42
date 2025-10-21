/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:54:12 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/21 16:45:15 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->resolution_set = 0;
	// cub->screen_height = WIN_H;
	// cub->screen_width = WIN_W;
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

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_cub	*cub;

	if (ac != 2)
		return (printf("Enter One Arg!\n"), 1);
	else if ((ft_strlen(av[1]) <= 4)
		|| (ft_strncmp(".cub", av[1] + ft_strlen(av[1]) - 4, 4)))
		return (printf("Enter .cub file extension\n"), 1);
	cub = malloc(sizeof(cub));
	if (!cub)
		return (perror("Cub3D"), 1);
	init_cub(cub);
	if (parse_map(cub, av[1]))
		return (0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, cub->screen_width, cub->screen_height, "Cub3D");
	mlx_key_hook(win, handel_key, NULL);
	mlx_loop(mlx);
	return (0);
}
