/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:20:36 by souchane          #+#    #+#             */
/*   Updated: 2024/02/26 18:25:13 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_exit(t_game *game)
{
	int i;
	int len;
	int j;
	
	len = 0;
	i = 0;
	while(game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'E')
			{
				game->x_exit = j;
				game->y_exit = i;
				len++;
			}
		}
		i++;
	}
	if (len != 1)
	{
		printf("Error\nmap has wrong exit!\n");
		exit(1);
	}
}