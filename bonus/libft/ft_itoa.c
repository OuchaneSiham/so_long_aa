/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:32:13 by souchane          #+#    #+#             */
/*   Updated: 2024/03/01 16:32:56 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*snbr;
	long	nb;
	int		i;

	nb = n;
	i = ft_count(nb);
	snbr = malloc(i + 1);
	if (!snbr)
		return (NULL);
	if (nb < 0)
	{
		snbr[0] = '-';
		nb *= -1;
	}
	snbr[i] = '\0';
	while (i && (nb != 0 || n == 0))
	{
		snbr[--i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (snbr);
}