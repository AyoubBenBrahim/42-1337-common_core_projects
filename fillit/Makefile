NAME = fillit
CC = gcc
FLAGS = -Werror -Wextra -Wall
SRCS = validate_file.c rearrange_tetriminos.c fillit.c ft_lstnew2.c ft_lstlen.c lstadd_at_end.c is_placeable.c create_board.c free_map.c print_map.c free_list.c manage_errors.c main.c libft/libft.a
HEADERS = fillit.h

all : $(NAME)

$(NAME) :
	@make re -C libft
	@$(CC) $(FLAGS) $(SRCS) -I $(HEADERS) -I libft/libft.h -o $(NAME)

clean :
	@make clean -C libft

fclean :
	@make fclean -C libft
	@rm -f $(NAME)

re : fclean all
