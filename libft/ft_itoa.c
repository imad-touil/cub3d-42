/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatouil <imatouil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:40:30 by imatouil          #+#    #+#             */
/*   Updated: 2024/11/10 01:41:47 by imatouil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_helper(char *t, int nbr, int len)
{
	t[len] = '\0';
	if (nbr == 0)
	{
		t[0] = '0';
		return (t);
	}
	if (nbr < 0)
	{
		t[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		t[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (t);
}

char	*ft_itoa(int nbr)
{
	int		n;
	int		len;
	char	*t;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 0;
	n = nbr;
	if (nbr <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	t = (char *)malloc(sizeof(char) * (len + 1));
	if (!t)
		return (NULL);
	return (my_helper(t, nbr, len));
}
