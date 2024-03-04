/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:18:11 by souchane          #+#    #+#             */
/*   Updated: 2024/03/04 19:44:36 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	checkmap3(char **tab, size_t firstline, size_t len)
{
	size_t	j;

	j = 0;
	while (len > j)
	{
		if (tab[j][0] != '1' || tab[j][firstline - 1] != '1')
		{
			printf("Error\nmap not surrounded by walls!\n");
			exit(1);
		}
		j++;
	}
}

void	checkmap2(char **tab, size_t firstline, size_t len)
{
	size_t	j;

	j = 0;
	while (firstline > j)
	{
		if (tab[0][j] != '1' || tab[len - 1][j] != '1')
		{
			printf("Error\nmap not surrounded by walls!\n");
			exit(1);
		}
		j++;
	}
}

void	checkmap1(char **tab, size_t firstline)
{
	size_t	i;

	i = 1;
	while (tab[i])
	{
		if (firstline != ft_strlen(tab[i]))
		{
			printf("Error\nMap not rectangular!\n");
			exit(1);
		}
		i++;
	}
}

void	checkmap(char **tab)
{
	size_t	len;
	size_t	firstline;

	len = 0;
	while (tab[len])
		len++;
	if (len <= 2)
	{
		printf("Error\nWrong map\n");
		exit(1);
	}
	firstline = ft_strlen(tab[0]);
	checkmap1(tab, firstline);
	checkmap2(tab, firstline, len);
	checkmap3(tab, firstline, len);
}
