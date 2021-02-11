# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 16:05:18 by aybouras          #+#    #+#              #
#    Updated: 2020/01/25 20:16:46 by aybouras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CFLAGS	=	-Werror -Wextra -Wall

SRCS	=	ft_strcpy.c\
			ft_strdup.c\
			ft_strstr.c\
			ft_atoi.c\
			ft_isspace.c\
			ft_strncmp.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_memset.c\
			ft_memcmp.c\
			ft_bzero.c\
			ft_memalloc.c\
			ft_memdel.c\
			ft_strnew.c\
			ft_strdel.c\
			ft_strsub.c\
			ft_putchar.c\
			ft_putnbr.c\
			ft_isdigit.c\
			ft_putstr.c\
			ft_strjoin.c\
			ft_strcat.c\
			is_number.c\
			ft_strlen.c

OBJS	=	$(SRCS:.c=.o)

HEADER	=	libft.h

all : $(NAME)

%.o : %.c $(HEADER)
	@printf "\033[32m\033[1m"
	gcc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[44m\033[93m\033[21mLibft...[OK]\033[49m\033[93m"

clean :
	@/bin/rm -f $(OBJS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

