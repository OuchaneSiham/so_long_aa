/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_null.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 15:17:48 by souchane          #+#    #+#             */
/*   Updated: 2024/03/05 15:38:12 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_null(t_game *game)
{
	int	i;

	i = 0;
	if (!game->exit)
		i = 1;
	else if (!game->coll)
		i = 1;
	else if (!game->player)
		i = 1;
	else if (!game->wall)
		i = 1;
	else if (!game->floor)
		i = 1;
	if (i == 1)
	{
		printf("erorr in the image \n");
		exit(0);
	}
}
