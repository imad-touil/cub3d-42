/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:54:12 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/20 21:37:36 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if (parse_map(cub, av[1]))
		return (0);
	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_W, WIN_H, "Cub3D");
	mlx_key_hook(win, handel_key, NULL);
	mlx_loop(mlx);
	return (0);
}
