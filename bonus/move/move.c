/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:58:16 by souchane          #+#    #+#             */
/*   Updated: 2024/02/29 15:59:04 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int move(int key, t_game *game)
{
	if(key == 13)
		move_up(game);
	else if(key == 1)
		move_down(game);
	else if(key == 0)
		move_left(game);
	else if(key == 2)
		move_right(game);
	return 1;
}
