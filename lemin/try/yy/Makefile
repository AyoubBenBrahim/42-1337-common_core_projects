NAME	=	lem-in

CFLAGS	=	-Werror -Wextra -Wall

FUNCTIONS	=	debuging_tools.c\
				fill_lst.c\
				ft_binary_search.c\
				ft_manage_queue.c\
				get_next.c\
				main.c\
				parse_line.c\
				quick_sort.c\
				store_path.c\
				dup_int.c\
				ft_balance_paths.c\
				ft_create_graph.c\
				ft_manipulate_path.c\
				join_int.c\
				manage_groups.c\
				parsing_tools.c\
				extra_parsing_tools.c\
				ft_bfs.c\
				ft_manage_path.c\
				ft_remove_memory_leak.c\
				lst_2array.c\
				merge_sort.c\
				printing.c\
				start_to_end_directly.c

HEADERS	=		inc/lem_in.h

OBJDIR	=		obj

SRCDIR	=		src

OBJS	=		$(addprefix $(OBJDIR)/,$(FUNCTIONS:%.c=%.o))

LFT		= 		libft/libft.a

all :			$(NAME)

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
				@gcc $(CFLAGS) -c $< -I./inc -o $@

$(OBJDIR):
				@mkdir $(OBJDIR)

$(LFT):
				@make -C libft

$(NAME) :		$(LFT) $(OBJDIR) $(OBJS)
				@gcc $(CFLAGS) $(LFT) $(OBJS) -o $(NAME)
				@echo "MAKEFILE LEM-IN...[OK]"

clean :
				@make clean -C libft
				@rm -rf $(OBJDIR)
				@echo "\033[41m\033[39m\033[1mRemoving LEM-IN objects...[OK]\033[49m\033[93m"

fclean :		clean
				@make fclean -C libft
				@rm -rf $(NAME)

re :			fclean all

