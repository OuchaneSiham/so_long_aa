/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_none_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:23:56 by souchane          #+#    #+#             */
/*   Updated: 2024/02/26 18:43:12 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_none_char(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while(game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] != 'P' && game->map[i][j] != 'E' && game->map[i][j] != 'C'
				&& game->map[i][j] != '0' && game->map[i][j] != '1')
			{
				printf("Error\nmap has wrong characters!\n");
				exit(1);
			}
		}
		i++;
	}
}