CC = gcc
CFLAGS = -I
FLAGS = -Werror -Wextra -Wall
SRCS = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
INCL = ./includes
OBJS = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all :
	$(CC) $(CFLAGS) $(INCL) $(FLAGS) -c $(SRCS)
	ar rc libft.a $(OBJS)
	ranlib libft.a

clean :
	/bin/rm -f $(OBJS)

fclean :
	/bin/rm -f libft.a
re : fclean all
