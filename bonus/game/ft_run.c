/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:48:30 by souchane          #+#    #+#             */
/*   Updated: 2024/03/01 17:07:12 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
void	addimgs(t_game *game)
{
	int ptr;
	game->wall = mlx_xpm_file_to_image(game->mlx, "imgs/wall.xpm", &ptr, &ptr);
	game->floor = mlx_xpm_file_to_image(game->mlx, "imgs/floor.xpm", &ptr, &ptr);
	game->player = mlx_xpm_file_to_image(game->mlx, "imgs/rick.xpm", &ptr, &ptr);
	game->exit = mlx_xpm_file_to_image(game->mlx, "imgs/door/d_c_0.xpm", &ptr, &ptr);
	game->coll = mlx_xpm_file_to_image(game->mlx, "imgs/coin/stone-0.xpm", &ptr, &ptr);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "imgs/player.xpm", &ptr, &ptr);
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
	else if (game->map[i][j] == 'A')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy, x ,y);
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
		game->open = 1;
		if(game->x_player == game->x_exit && game->y_player == game->y_exit)
		{
			ft_putstr("you win\n");
			exit(0);
		}
	}
}

void	coll_loop(t_game *game)
{
	int ptr;
	if (game->fram_coin == 8)
		game->coll = mlx_xpm_file_to_image(game->mlx, "imgs/coin/stone-0.xpm", &ptr, &ptr);
	else if (game->fram_coin == 16)
		game->coll = mlx_xpm_file_to_image(game->mlx, "imgs/coin/stone-1.xpm", &ptr, &ptr);
	else if (game->fram_coin == 24)
		game->coll = mlx_xpm_file_to_image(game->mlx, "imgs/coin/stone-2.xpm", &ptr, &ptr);
	else if (game->fram_coin == 32)
		game->coll = mlx_xpm_file_to_image(game->mlx, "imgs/coin/stone-3.xpm", &ptr, &ptr);
	if (game->fram_coin == 32)
		game->fram_coin = -1;
	game->fram_coin++;
}
void	door_loop(t_game *game)
{
	int ptr;
	if (game->open)
	{
		if (game->frame_door == 0)
			game->exit= mlx_xpm_file_to_image(game->mlx, "imgs/door/d_o_0.xpm", &ptr, &ptr);
		else if (game->frame_door == 10)
			game->exit= mlx_xpm_file_to_image(game->mlx, "imgs/door/d_o_1.xpm", &ptr, &ptr);
		else if (game->frame_door == 20)
			game->exit= mlx_xpm_file_to_image(game->mlx, "imgs/door/d_o_2.xpm", &ptr, &ptr);
	}
	else
	{
		if (game->frame_door == 0)
			game->exit = mlx_xpm_file_to_image(game->mlx, "imgs/door/d_c_0.xpm", &ptr, &ptr);
		else if (game->frame_door == 10)
			game->exit = mlx_xpm_file_to_image(game->mlx, "imgs/door/d_c_1.xpm", &ptr, &ptr);
		else if (game->frame_door == 20)
			game->exit = mlx_xpm_file_to_image(game->mlx, "imgs/door/d_c_2.xpm", &ptr, &ptr);
	}
	if (game->frame_door == 20)
		game->frame_door = -1;
	game->frame_door++;
}
void message(t_game *game)
{
	char *itoa;
	
	itoa = ft_itoa(game->count);
	mlx_string_put(game->mlx, game->mlx_win, 5, 5, 0x0, itoa);
	free(itoa);
}
int gameloop(t_game *game)
{
	coll_loop(game);
	door_loop(game);
	mlx_clear_window(game->mlx, game->mlx_win);
	buildimgs(game);
	message(game);
	return (1);
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
	game.fram_coin = 0;
	game.frame_door = 0;
	game.open = 0;
	mlx_hook(game.mlx_win, 2, 0, move, &game);
	mlx_hook(game.mlx_win, 17, 0, quit, &game);
	mlx_loop_hook(game.mlx, gameloop, &game);
	mlx_loop(game.mlx);
}
