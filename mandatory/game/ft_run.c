/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:48:30 by souchane          #+#    #+#             */
/*   Updated: 2024/02/29 16:06:39 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
void	addimgs(t_game *game)
{
	int ptr;
	game->wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", &ptr, &ptr);
	game->floor = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm", &ptr, &ptr);
	game->player = mlx_xpm_file_to_image(game->mlx, "imgs/player.xpm", &ptr, &ptr);
	game->exit = mlx_xpm_file_to_image(game->mlx, "imgs/exit.xpm", &ptr, &ptr);
	game->coll = mlx_xpm_file_to_image(game->mlx, "imgs/coll.xpm", &ptr, &ptr);
}

void imgsesss(t_game *game, int x, int y , int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, x ,y);
	else if (game->map[i][j] == '0')
	{
		if (i == game->y_exit && j == game->x_exit)
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, x ,y);
		else
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, x ,y);
	}
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->coll, x ,y);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, x ,y);
	
}

void	buildimgs(t_game *game)
{
	int i;
	int j;
	int x;
	int y;
	
	i = 0;
	y = 0;
	mlx_clear_window(game->mlx, game->mlx_win);
	while(game->map[i])
	{
		j = 0;
		x = 0;
		while(game->map[i][j])
		{
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, x ,y);
			if (game->x_exit == j && game->y_exit == i)
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, x ,y);
			imgsesss(game, x, y, i, j);
			j++;
			x += 64;
		}
		y += 64;
		i++;
	}
}

void checkwin(t_game *game)
{
	int i;
	int j;
	int len;
	
	i = 0;
	len = 0;
	while(game->map[i])
	{
		j = 0;
		while(game->map[i][j])
		{
			if (game->map[i][j] == 'C')
				len++;
			j++;
		}
		i++;
	}
	if(len == 0)
	{
		if(game->x_player == game->x_exit && game->y_player == game->y_exit)
		{
			ft_putstr("you win\n");
			exit(0);
		}
	}
}

void run(char *str)
{
	
	t_game game;

	game.map_str = str;
	game.map = ft_split(str, '\n');
	checkmap(game.map);
	check(&game);
	game.win_h = ft_strtab(game.map) * 64;
	game.win_w = ft_strlen(game.map[0]) * 64;
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.win_w, game.win_h, "siham" );
	addimgs(&game);
	buildimgs(&game);
	game.count = 0;
	mlx_hook(game.mlx_win, 2, 0, move, &game);
	mlx_hook(game.mlx_win, 17, 0, quit, &game);
	mlx_loop(game.mlx);
}
