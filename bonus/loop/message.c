/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:09:14 by souchane          #+#    #+#             */
/*   Updated: 2024/03/04 22:40:02 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	message(t_game *game)
{
	char	*itoa;

	itoa = ft_itoa(game->count);
	mlx_string_put(game->mlx, game->mlx_win, 5, 5, 0xFFFF00, itoa);
	free(itoa);
}
