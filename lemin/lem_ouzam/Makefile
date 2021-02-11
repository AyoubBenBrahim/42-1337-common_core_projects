# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 21:38:19 by ouzamhar          #+#    #+#              #
#    Updated: 2020/11/07 11:55:52 by aybouras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	lem-in

SRC		=	main.c struct.c func.c read.c get_ants.c ft_malloc.c\
	  		get_nodes.c get_part.c nodes.c create_map.c links.c \
			algo.c augment_flow.c creat_path.c score.c shortestpath.c\
			queue.c share_ants.c start_to_end.c printing.c edge.c free_mem.c

OBJ		= $(SRC:.c=.o)

LIB		= libft/libft.a

all : makelibft $(NAME)

$(NAME) : $(LIB) $(OBJ)
	@gcc $(OBJ) -o $(NAME) $(LIB)

makelibft :
	@make -C libft

$(OBJ) : %.o : %.c lem_in.h
	@gcc -Wall -Wextra -Werror -c $< -o $@  -I libft
	@echo "\033[44m\033[93m\033[21mLem-in...[OK]\033[49m\033[93m"

clean :
	make clean -C libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)
re : fclean all
