/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:23:37 by souchane          #+#    #+#             */
/*   Updated: 2024/03/04 22:14:22 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **tab, int x, int y)
{
	if (tab[y][x] != '0' && tab[y][x] != 'C'
	&& tab[y][x] != 'P' && tab[y][x] != 'E')
		return ;
	tab[y][x] = 'S';
	flood_fill(tab, x - 1, y);
	flood_fill(tab, x + 1, y);
	flood_fill(tab, x, y - 1);
	flood_fill(tab, x, y + 1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	check_path(t_game *game)
{
	int		x;
	int		y;
	char	**tab;

	tab = ft_split(game->map_str, '\n');
	x = game->x_player;
	y = game->y_player;
	flood_fill(tab, x, y);
	game->i = 0;
	while (tab[game->i])
	{
		game->j = 0;
		while (tab[game->i][game->j])
		{
			if (tab[game->i][game->j] == 'C')
			{
				printf("Error\nplayer can not access to all colles.!\n");
				exit(1);
			}
			game->j++;
		}
		game->i++;
	}
	free_tab(tab);
}
