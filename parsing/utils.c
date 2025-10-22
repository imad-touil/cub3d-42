/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:41:14 by imatouil          #+#    #+#             */
/*   Updated: 2025/10/22 11:28:17 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*skip_white_space(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}
void	error(t_cub *cub, char *error)
{
	printf("%s%s\n", RED, error);
	// clean_up(cub); TODO
	cub->screen_height = 1337; // just for compiling flags;
	exit(EXIT_FAILURE);
}