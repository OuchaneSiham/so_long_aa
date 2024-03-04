# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchane <souchane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 16:14:00 by souchane          #+#    #+#              #
#    Updated: 2024/03/02 17:13:27 by souchane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		    = so_long
F			    = -Wall -Wextra -Werror
CC			    = cc
RM			    = rm -f
HEADER		    = so_long.h
LIBFT			= libft/ft_putstr libft/ft_strcmp libft/ft_putnbr libft/ft_split libft/ft_strlen \
					libft/ft_strtab libft/get_next_line_utils libft/get_next_line libft/ft_itoa
GAME			= game/ft_run 
CHECK			= check/ft_check_coll check/ft_check_exit check/ft_check_player check/ft_check_none_char \
					check/ft_check_path  check/ft_check_file  check/ft_check	check/ft_checkmap 
MOVE            = move/move_down move/move_right move/move_left move/move_up move/move move/quit
LOOP			= loop/message loop/coll_loop loop/door_loop loop/gameloop
FILES 			= $(LIBFT) $(CHECK) $(GAME) $(MOVE) $(LOOP) main
FRAMEWORKS 		= -lmlx -framework OpenGL -framework AppKit

SOURCE_F	= $(FILES:=.c)
OBJECT_F	= $(FILES:=.o)


all : $(NAME) 

$(NAME): $(OBJECT_F) $(HEADER)
	$(CC) $(OBJECT_F) $(FRAMEWORKS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(F) -c $< -o $@ 

clean :
	 $(RM) $(OBJECT_F)

fclean : clean
	$(RM) $(NAME)

re : fclean all 
