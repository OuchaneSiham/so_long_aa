/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:08:15 by souchane          #+#    #+#             */
/*   Updated: 2024/03/04 22:40:19 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	gameloop(t_game *game)
{
	coll_loop(game);
	door_loop(game);
	mlx_clear_window(game->mlx, game->mlx_win);
	buildimgs(game);
	message(game);
	return (1);
}
