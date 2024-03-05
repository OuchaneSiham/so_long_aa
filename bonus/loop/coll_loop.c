/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coll_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:08:54 by souchane          #+#    #+#             */
/*   Updated: 2024/03/05 12:57:47 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	coll_loop(t_game *game)
{
	int	ptr;

	if (game->fram_coin == 8)
		game->coll = mlx_xpm_file_to_image(game->mlx,
				"ims/coin/st-0.xpm", &ptr, &ptr);
	else if (game->fram_coin == 16)
		game->coll = mlx_xpm_file_to_image(game->mlx,
				"ims/coin/st-1.xpm", &ptr, &ptr);
	else if (game->fram_coin == 24)
		game->coll = mlx_xpm_file_to_image(game->mlx,
				"ims/coin/st-2.xpm", &ptr, &ptr);
	else if (game->fram_coin == 32)
		game->coll = mlx_xpm_file_to_image(game->mlx,
				"ims/coin/st-3.xpm", &ptr, &ptr);
	if (game->fram_coin == 32)
		game->fram_coin = -1;
	game->fram_coin++;
}
