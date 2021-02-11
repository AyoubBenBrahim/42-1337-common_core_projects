# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/12 13:41:53 by ouzamhar          #+#    #+#              #
#    Updated: 2020/11/07 11:50:48 by aybouras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Werror -Wextra -Wall

NAME= libft.a

SRC=	ft_atoi.c ft_itoa.c ft_lstnew.c ft_memdel.c ft_putnbr.c ft_strcmp.c ft_strjoin.c \
		ft_strncpy.c ft_strtrim.c ft_bzero.c ft_lstadd.c ft_lstrev.c ft_memmove.c ft_putnbr_fd.c\
		ft_strcpy.c ft_strlcat.c ft_strnequ.c ft_swap.c ft_isalnum.c ft_lstdel.c ft_memalloc.c\
		ft_memset.c ft_putstr.c ft_strdel.c ft_strlen.c ft_strnew.c ft_swaplst.c ft_isalpha.c\
		ft_lstdelone.c ft_memccpy.c ft_putchar.c ft_putstr_fd.c ft_strdup.c ft_strmap.c\
		ft_strnstr.c ft_swpcntlst.c ft_isascii.c ft_lstiter.c ft_memchr.c ft_putchar_fd.c\
		ft_strcat.c ft_strequ.c ft_strmapi.c ft_strrchr.c ft_tolower.c ft_isdigit.c\
		ft_lstlen.c ft_memcmp.c ft_putendl.c ft_strchr.c ft_striter.c ft_strncat.c ft_strstr.c\
		ft_toupper.c ft_isprint.c ft_lstmap.c ft_memcpy.c ft_putendl_fd.c ft_strclr.c ft_striteri.c\
		ft_strncmp.c ft_strsub.c

OBJS	=	$(SRC:.c=.o)

HEADER	=	libft.h

all : $(NAME)

%.o : %.c $(HEADER)
	@printf "\033[32m\033[1m"
	@gcc $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\033[44m\033[93m\033[21mLibft...[OK]\033[49m\033[93m"

clean :
	@/bin/rm -f $(OBJS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
