# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 14:34:47 by ayb*****          #+#    #+#              #
#    Updated: 2019/12/09 15:17:46 by ayb*****         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ayb*****.filler

CFLAGS	=	-Werror -Wextra -Wall

FUNCTIONS	=	filler.c\
				get_next_line.c\
				leaks_black_hole.c\
				manage_errors.c\
				ft_char2int.c\
				fill_sides.c\
				heat_map.c\
				check_if_placeable.c\
				store_board.c\
				store_piece.c\
				trim_piece.c\
				set_score.c\
				is_placeable.c

HEADERS	=		inc/filler.h

OBJDIR	=		objs

SRCDIR	=		srcs

OBJS	=		$(addprefix $(OBJDIR)/,$(FUNCTIONS:%.c=%.o))

LFT		= 		libft/libft.a

all :			$(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
				@printf "\033[32m\033[1m"
				@gcc $(CFLAGS) -c $< -I./inc -o $@

$(OBJDIR):
				@mkdir -p $(OBJDIR)

$(LFT):
				@make -C libft

$(NAME) :		$(LFT) $(OBJDIR) $(OBJS)
				@gcc $(CFLAGS) $(LFT) $(OBJS) -o $(NAME)
				@echo "\033[44m\033[93m\033[21mMAKEFILE FILLER...[OK]\033[49m\033[93m"

clean :
				@make clean -C libft
				@rm -rf $(OBJDIR)
				@echo "\033[41m\033[39m\033[1mRemoving FILLER objects...[OK]\033[49m\033[93m"

fclean :		clean
				@make fclean -C libft
				@rm -rf $(NAME)

re :			fclean all
