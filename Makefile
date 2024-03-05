# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchane <souchane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/27 16:14:00 by souchane          #+#    #+#              #
#    Updated: 2024/03/05 15:22:59 by souchane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		    = so_long
NAME_BONUS		= so_long_bonus
F			    = -Wall -Wextra -Werror
CC			    = cc
RM			    = rm -f
FRAMEWORKS 		= -lmlx -framework OpenGL -framework AppKit
HEADER		    = mandatory/so_long.h
HEADER_BONUS    = bonus/so_long.h
LIBFT			= mandatory/libft/ft_putstr mandatory/libft/ft_strcmp mandatory/libft/ft_putnbr mandatory/libft/ft_split mandatory/libft/ft_strlen \
					mandatory/libft/ft_strtab mandatory/libft/get_next_line_utils mandatory/libft/get_next_line
GAME			= mandatory/game/ft_run mandatory/game/ft_null
CHECK			= mandatory/check/ft_check_coll mandatory/check/ft_check_exit mandatory/check/ft_check_player mandatory/check/ft_check_none_char \
				mandatory/check/ft_check_path  mandatory/check/ft_check_file  mandatory/check/ft_check	mandatory/check/ft_checkmap 
MOVE            = mandatory/move/move_down mandatory/move/move_right mandatory/move/move_left mandatory/move/move_up mandatory/move/move mandatory/move/quit		
FILES 			= $(LIBFT) $(CHECK) $(GAME) $(MOVE) mandatory/main

LIBFT_BONUS     	= bonus/libft/ft_putstr bonus/libft/ft_strcmp bonus/libft/ft_putnbr bonus/libft/ft_split bonus/libft/ft_strlen \
				 	 bonus/libft/ft_strtab bonus/libft/get_next_line_utils bonus/libft/get_next_line bonus/libft/ft_itoa
GAME_BONUS			= bonus/game/ft_run 
CHECK_BONUS			= bonus/check/ft_check_coll bonus/check/ft_check_exit bonus/check/ft_check_player bonus/check/ft_check_none_char \
						 bonus/check/ft_check_path  bonus/check/ft_check_file  bonus/check/ft_check	bonus/check/ft_checkmap 
MOVE_BONUS          = bonus/move/move_down bonus/move/move_right bonus/move/move_left bonus/move/move_up bonus/move/move bonus/move/quit
LOOP_BONUS 			= bonus/loop/coll_loop bonus/loop/door_loop bonus/loop/gameloop bonus/loop/message bonus/loop/ft_null
FILES_BONUS 		= $(LIBFT_BONUS) $(CHECK_BONUS) $(GAME_BONUS) $(MOVE_BONUS) $(LOOP_BONUS) bonus/main	 

SOURCE_F	= $(FILES:=.c)
OBJECT_F	= $(FILES:=.o)

SOURCE_FB	= $(FILES_BONUS:=.c)
OBJECT_FB	= $(FILES_BONUS:=.o)

%.o: %.c $(HEADER) $(HEADER_BONUS)
	$(CC) $(F) -c $< -o $@
 
all : $(NAME) 

$(NAME): $(OBJECT_F) $(HEADER)
	$(CC) $(OBJECT_F) $(FRAMEWORKS) -o $(NAME)

bonus : $(NAME_BONUS) 

$(NAME_BONUS): $(OBJECT_FB) $(HEADER_BONUS)
	$(CC) $(OBJECT_FB) $(FRAMEWORKS) -o $(NAME_BONUS)
clean :
	 $(RM) $(OBJECT_F) $(OBJECT_FB)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all 
