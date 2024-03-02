# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchane <souchane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 16:14:00 by souchane          #+#    #+#              #
#    Updated: 2024/03/02 15:50:33 by souchane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		    = so_long
F			    = -Wall -Wextra -Werror
CC			    = cc
RM			    = rm -f
HEADER		    = mandatory/so_long.h
LIBFT			= mandatory/libft/ft_putstr mandatory/libft/ft_strcmp mandatory/libft/ft_putnbr mandatory/libft/ft_split mandatory/libft/ft_strlen \
					mandatory/libft/ft_strtab mandatory/libft/get_next_line_utils mandatory/libft/get_next_line 
GAME			= mandatory/game/ft_run 
CHECK			= mandatory/check/ft_check_coll mandatory/check/ft_check_exit mandatory/check/ft_check_player mandatory/check/ft_check_none_char \
					mandatory/check/ft_check_path  mandatory/check/ft_check_file  mandatory/check/ft_check	mandatory/check/ft_checkmap 
MOVE            = mandatory/move/move_down mandatory/move/move_right mandatory/move/move_left mandatory/move/move_up mandatory/move/move mandatory/move/quit		
FILES 			= $(LIBFT) $(CHECK) $(GAME) $(MOVE) mandatory/main
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
