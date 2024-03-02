/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_coll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:19:31 by souchane          #+#    #+#             */
/*   Updated: 2024/02/26 18:25:08 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check_coll(t_game *game)
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
			if (game->map[i][j] == 'C')
				len++;
		}
		i++;
	}
	if (len == 0)
	{
		printf("Error\n no collection!\n");
		exit(1);
	}
}