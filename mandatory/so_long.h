/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:40:37 by souchane          #+#    #+#             */
/*   Updated: 2024/02/29 16:15:42 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
# include <limits.h>
#include <mlx.h>

typedef struct s_game
{
	char **map;
	char *map_str;
	int	x_player;
	int	y_player;
	int	x_exit;
	int	y_exit;
	void *mlx;
	void *mlx_win;
	int win_h;
	int win_w;
	void *wall;
	void *floor;
	void *player;
	void *exit;
	void *coll;
	int count;

	
} t_game;

// #define BUFFER_SIZE 1

// check
void check_coll(t_game *game);
void check_exit(t_game *game);
int ft_check_file(char *f_str);
void check_none_char(t_game *game);
void check_path(t_game *game);
void check_player(t_game *game);
void check(t_game *game);
void checkmap(char **tab);
//libft
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif
char	*get_str(char **str);
char	*get_next_line(int fd);
char	*gnl(int fd, char **line, char *buffer);
char	*ft_substr_gnl(char *s, int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr_gnl(char *str, int c);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strcpy_gnl(char *dest, char *src);
char	**ft_split(char const *s, char c);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
size_t	ft_strlen(const char *s);
int		ft_strtab(char **tab);
int		ft_strcmp(char *s1, char *s2);
//game
void	run(char *str);
void checkwin(t_game *game);
void	buildimgs(t_game *game);

//move
int  move(int key, t_game *game);
void move_right(t_game *game);
void move_left(t_game *game);
void move_down(t_game *game);
void move_up(t_game *game);
int quit(t_game *game);
#endif
