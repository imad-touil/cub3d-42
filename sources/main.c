/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:54:12 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/20 11:56:34 by imatouil         ###   ########.fr       */
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

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_W, WIN_H, "Cub3D");
	mlx_key_hook(win, handel_key, NULL);
	mlx_loop(mlx);
	int	fd;
	fd = open("test.txt", O_RDONLY);
	char *str;
	str = get_next_line(fd);
	int i = 0;
	while (str)
	{
		printf("%d  %s", i++, str);
		str = get_next_line(fd);
	}
	return (0);
}
