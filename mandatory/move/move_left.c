/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:00:38 by souchane          #+#    #+#             */
/*   Updated: 2024/02/29 16:03:21 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

void move_left(t_game *game)
{
	if(game->map[game->y_player][game->x_player - 1] != '1')
	{
		game->map[game->y_player][game->x_player - 1] = 'P';
		game->map[game->y_player][game->x_player] = '0';
		game->x_player -= 1;
		buildimgs(game);
		game->count++;
		ft_putstr("left: ");
		ft_putnbr(game->count);
		ft_putchar('\n');
		checkwin(game);
	}
}
