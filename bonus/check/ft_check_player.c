/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:20:10 by souchane          #+#    #+#             */
/*   Updated: 2024/02/26 18:25:26 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_player(t_game *game)
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
			if (game->map[i][j] == 'P')
			{
				game->x_player = j;
				game->y_player = i;
				len++;
			}
		}
		i++;
	}
	if (len != 1)
	{
		printf("Error\nmap has wrong player!\n");
		exit(1);
	}
}