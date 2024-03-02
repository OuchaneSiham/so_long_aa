/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:23:37 by souchane          #+#    #+#             */
/*   Updated: 2024/02/27 20:34:25 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void flood_fill(char **tab, int x, int y)
{
	if (tab[y][x] != '0' && tab[y][x] != 'C'  && tab[y][x] != 'P' && tab[y][x] != 'E')
		return ;
	tab[y][x] = 'S';
	flood_fill(tab, x - 1, y);
	flood_fill(tab, x + 1, y);
	flood_fill(tab, x , y - 1);
	flood_fill(tab, x , y + 1);
}

void check_path(t_game *game)
{
	int x;
	int y;
	int i;
	int j;
	char **tab;

	tab = ft_split(game->map_str, '\n');
	x = game->x_player;
	y = game->y_player;
	flood_fill(tab, x, y);
	i = 0;
	while(tab[i])
	{
		j = 0;
		while(tab[i][j])
		{
			if (tab[i][j] == 'C')
			{
				printf("Error\nplayer can not access to all colles.!\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}