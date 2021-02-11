/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 09:23:30 by aybouras          #+#    #+#             */
/*   Updated: 2020/10/29 12:52:18 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
#define BUFF_SIZE 2
#define ERROR 1
# define exiter exit(0); // ************** del

# include "../libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h> // ******************delete this*******************

typedef enum			e_boolean
{
	FALSE,
	TRUE,
}						t_boolean;

typedef struct		s_stack
{
	int				room;
	int				len;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*parent;
	struct s_stack	*predecessor;
}					t_stack;

typedef struct			s_vertices
{
	char				*vertex_name;
	int					coord_x;
	int					coord_y;
	struct s_vertices	*next;
}						t_vertices;

typedef struct			s_list_node
{
	int					nbr_edges;
	int					dst;
	int					c;
	int					f;
	// int					father;
	// struct s_list_node	*real_predecessor;
	// int					real_predecessor;
	int					edge_cap;
	int					parent;
	int					*path;
	int					path_id;
	int					path_verteces;
	int					local_score;
	int					*track_ants;
	int					remaining;
	int					waiting_room;
	int					path_capacity;
	int					starting_ant;
	struct s_list_node	*next;
	struct s_list_node	*next_p;
}						t_list_node;

typedef struct			s_lst
{
	t_list_node			*list;
	t_list_node			*root;
}						t_lst;

typedef struct			s_graph
{
	t_lst				*tab;
	int					nb_v;
}						t_graph;

typedef struct			s_groups
{
	t_list_node			*path_holder;
	t_list_node			*last_ptr;
	int					group_id;
	int					*merged_paths;
	int					merged_paths_length;
	int					total_verteces;
	// int					global_score;
	int					nbr_paths;
	int					counter;
	int					len;
	struct s_groups		*next;
	struct s_groups		*next_gr;
}						t_groups;

typedef struct			s_parse
{
	// char				*full_line;
	t_graph				*graph;
	t_vertices			*rooms_lst;
	t_groups			*the_group;
	t_groups			*last_created_grp;
	t_groups			*best_score_grp;

	t_stack 			*stack;
	t_stack 			*lstack;
	t_stack 			*last_start;;
	t_stack		*iterator;
	int					stack_len;


	t_groups			*re_groupe;
	t_groups			*last_reg;

	t_list_node			*detected;
	t_list_node			*last_p;
	int					*discovered;
	int					visited;
	// int					*adjs_of_start;
	// int					index;
	// int					last_poped;

	t_list_node			*best_score_pat;
	t_boolean			start_is_set;
	// t_boolean			rooms_storage_finished;
	t_boolean			end_is_set;
	t_boolean			there_is_intersection;
	// t_boolean			hyphen_exist;
	// t_boolean			is_intersection;
	// t_boolean			is_first_path;
	char				**array_of_rooms;
	char				*start;
	char				*end;
	char				*line;
	char				*line_tmp;
	char				*the_rest;
	// t_boolean			parse_error;
	int					*path;
	long				nbr_ants;
	int					start_index;
	int					end_index;
	int					nbr_paths;
	int					total_vertices;
	int					path_nbr_vertices;
	// int					old_score;
	// int					new_score;
	// int					to_stock;
	int					path_length;
	int					smallest_score;
	int					group_id;

	t_list_node			*delet;

}						t_parse;

typedef struct			s_qu
{
	t_list_node			*rear;
	t_list_node			*front;
	t_list_node			*queue;
}						t_qu;

typedef struct			s_balance
{
	int					balance;
	int					max_len;
	int					remained_total;
	int					res;
	int					cap_add;
}						t_balance;

// t_vertices				*join_list(t_vertices *right, t_vertices *left);
t_vertices				*join_list(t_parse *prs, t_vertices *right, t_vertices *left);
t_graph					*ft_create_graph(int nb);
t_list_node				*ft_create_list_node(int dst);
t_list_node				*ft_get_node(t_list_node *list, int vertex);
int						*join_tab_int(int tab1[], int tab2[],
							int len1, int len2);
int						ft_binary_int_search(int *global_arr,
							int arr_size, int value_to_search);
int						ft_enqueue(t_qu *q, int vertex);
int						ft_binary_search(t_parse *prs, char **tab,
							char *vertex_name);
int						ft_bfs(t_parse *prs, int flow);
int						*ft_strdup_int(int *s1, int start, int size);
int						free_bfs_memory(t_parse *prs, int *visited, t_qu *q);
int						ft_strdel_int(int **as);
int						ft_strequ_int(int *s1, int *s2, int size);
int						ft_manipulate_path(t_parse *prs, t_qu *q,
							int *visited, int flow);
int						ft_queue_is_empty(t_qu *queue);
// char					**parse_line(char *str, char c);
char					**parse_line(t_parse *prs, char *str, char c);
void					fill_lst(t_vertices **head, char **array);
// void					merge_sort(t_vertices **original_head);
void					merge_sort(t_parse *prs, t_vertices **original_head);
void					lst_2array(t_parse *prs);
void					ft_create_link(t_graph *gr, int src, int dest);
void					ft_create_queue_node(t_qu *q);
void					ft_dequeue(t_qu *q);
void					ft_free_graph(t_graph *gr);
void					ft_free_lst(t_list_node **lst);
void					ft_free_vlst(t_vertices **lst);
void					ft_manage_path(t_parse *prs);
void					ft_block_path(t_parse *prs, int *tab);
void					ft_store_path_in_group(t_parse *prs, int path_length,
							t_groups **store_path, t_groups **last_grp_ptr);
void					send_ants(t_parse *prs);
void					ft_balance_paths(t_parse *prs, t_groups *group,
							int best_score_path_id);
// void					ft_rescue_memory(t_parse *prs);
void					ft_rescue_memory(t_parse *prs, int flag);
// void					ft_create_first_group(t_parse *prs,
// 							t_groups ***store_path, int path_length,
// 								t_groups **last_grp_ptr);
void	create_group(t_parse *prs);
// void					ft_store_in_same_group(t_parse *prs,
// 							t_groups **group_to_store, int path_length);
// void store_in_same_grp(t_parse *prs, t_groups **selected_grp);
void store_in_same_grp(t_parse *prs);
// void					ft_create_new_group(t_parse *prs, int path_length,
// 								t_groups **last_grp_ptr);
void	create_new_grp(t_parse *prs);
void					ft_manage_flow(t_parse *prs);
void					ft_int_tab_set(int *tmp, int c, size_t len);

int						get_next(const int fd, char **line, t_parse *prs);
void					quick_sort(int tab[], int start, int end);
void					calc_score(t_parse *prs);

void	print_groups(t_parse *prs);
void	printArray(int array[], int size);
void	print_graph(t_parse *prs);
void	print_lst(t_parse prs, t_vertices *lst);
void	groups(t_parse *prs);
void	groups2(t_parse *prs);
void	print_this_group(t_parse *prs, t_groups *group);
void					re_groupe(t_parse *prs);

// void	dfs(t_parse *prs);
int		push(t_parse *prs, int room, int parent);
// void	count_adjs(t_parse *prs);


// void		fitox(t_parse *prs);
void		breadth_first_search(t_parse *prs, int the_start, int the_end);
void	ant_eater(t_parse *prs);
void		print_stack(t_parse *prs);
void		free_stack(t_parse *prs);

void    print_adj_addr(t_parse *prs);

#endif
