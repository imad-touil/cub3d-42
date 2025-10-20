/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:55:31 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/20 15:56:36 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_map(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}