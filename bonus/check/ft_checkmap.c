/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:18:11 by souchane          #+#    #+#             */
/*   Updated: 2024/02/26 18:52:36 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void checkmap(char **tab)
{
	size_t 	len;
	size_t	firstline;
	size_t	i;
	size_t		j;
	len = 0;
	while(tab[len])
		len++;
	if(len <= 2)
	{
		printf("Error\nWrong map\n");
		exit(1);
	}
	firstline = ft_strlen(tab[0]);
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
	j = 0; 
	while(firstline > j)
	{
		if (tab[0][j] != '1' ||  tab[len - 1][j] != '1')
		{
			printf("Error\nmap not surrounded by walls!\n");
			exit(1);
		}
		j++;
	}
	j = 0;
	while(len > j)
	{
		if (tab[j][0] != '1' ||  tab[j][firstline - 1] != '1')
		{
			printf("Error\nmap not surrounded by walls!\n");
			exit(1);
		}
		j++;
	}
}