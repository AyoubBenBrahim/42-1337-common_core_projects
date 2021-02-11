NAME = fdf
CC = gcc
FLAGS = -Werror -Wextra -Wall
SRCS = main.c ft_parse.c destroy_leaks.c ft_option_init.c ft_rotate.c draw.c mouse_press.c key_press.c check_file.c menu.c read_file.c string_put.c draw_line.c do_conversions.c libft/libft.a
HEADERS = fdf.h
FRAME-WORKS = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) :
	@make re -C libft
	@$(CC) $(FLAGS) $(SRCS) $(FRAME-WORKS) -I $(HEADERS) -I  libft/libft.h -o $(NAME)
	@echo "\033[0;32mlibft and fdf files were created\033[0m"

clean :
	@make clean -C libft
	@echo "\033[0;31mobject files were deleted\033[0m"

fclean :
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "\033[0;31mfiles were deleted\033[0m"

re : fclean all
