/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:22:12 by souchane          #+#    #+#             */
/*   Updated: 2024/02/26 18:25:29 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void check(t_game *game)
{
	check_player(game);
	check_coll(game);
	check_exit(game);
	check_none_char(game);
	check_path(game);
}