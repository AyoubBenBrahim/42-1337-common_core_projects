/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 09:23:30 by aybouras          #+#    #+#             */
/*   Updated: 2020/10/25 09:23:44 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H
#define BUFF_SIZE 2

#include "../libft/libft.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h> // ******************delete this*******************

typedef enum e_boolean
{
	FALSE,
	TRUE,
} t_boolean;

typedef struct s_vertices
{
	char *vertex_name;
	int coord_x;
	int coord_y;
	struct s_vertices *next;
} t_vertices;

typedef struct s_list_node
{
	int dst;
	int flow;
	int parent;
	int *path;
	int path_id;
	int path_verteces; // nb of vertices per path
	int local_score;
	int *track_ants;
	int remaining;
	int waiting_room;
	int path_capacity;
	int starting_ant;
	struct s_list_node *next;
} t_list_node;

typedef struct s_lst
{
	t_list_node *list;
} t_lst;

typedef struct s_graph
{
	int nb_v;
	t_lst *tab;
} t_graph;

typedef struct s_groups
{
	int group_id;
	t_list_node *path_node;
	t_list_node *last_ptr;
	int *merged_paths;
	int merged_paths_length;
	int total_verteces;
	int global_score;
	int nbr_paths;
	int counter;
	int len;
	struct s_groups *next;
} t_groups;

typedef struct s_parse
{
	int nbr_ants;
	char *start;
	char *end;

	char *line;
	// char *the_rest[4864];
	char *the_rest;

t_boolean parse_error;

	int start_index;
	int end_index;
	int nbr_paths;
	int total_vertices;	   // nb of vertices in the whole graph
	int path_nbr_vertices; // total paths vertices
	int old_score;
	int new_score;
	int to_stock;
	int *path;
	int path_verteces;
	int save_smallest_score;
	t_boolean start_is_set;
	t_boolean rooms_storage_finished;
	t_boolean end_is_set;
	t_boolean hyphen_exist;
	t_boolean is_intersection;
	t_graph *graph;
	t_vertices *rooms_lst;
	t_vertices *lst1;
	t_vertices *lst2;
	t_vertices *lst3;
	t_vertices *lst4;
	t_vertices *lst5;
	t_groups *store_regular_path;
	t_groups *reg_last_ptr;
	t_groups *store_intersected_path;
	t_groups *inter_last_ptr;
	t_boolean is_first_path;
	t_groups *small_score_group;
	t_list_node *small_score_path;
	char **array_of_rooms;

} t_parse;

typedef struct s_qu
{
	t_list_node *rear;
	t_list_node *front;
	t_list_node *queue;
} t_qu;

int *join_tab_int(int tab1[], int tab2[], int len1, int len2);
int ft_binary_int_search(int *global_arr, int arr_size, int value_to_search);
// int get_next_line(const int fd, char **line);
char **parse_line(char *str, char c);
void fill_lst(t_vertices **head, char **array);
void merge_sort(t_parse *prs, t_vertices **original_head);
t_vertices *join_list(t_parse *prs, t_vertices *right, t_vertices *left);
void lst_2array(t_parse *prs);
void quick_sort(int tab[], int start, int end);
t_graph *ft_create_graph(int nb);
t_list_node *ft_create_list_node(int dst);
void ft_create_link(t_graph *gr, int src, int dest);
void ft_create_queue_node(t_qu *q);
void ft_dequeue(t_qu *q);
void ft_enqueue(t_qu *queue, int vertex);
int ft_bianry_search(t_parse *prs, char **tab, char *vertex_name);
void print_graph(t_graph *gr); // to delete
void ft_print_queue(t_qu q);   // to delete
void ft_free_graph(t_graph *gr);
void ft_free_lst(t_list_node **lst);
void ft_free_vlst(t_vertices **lst);
int ft_queue_is_empty(t_qu *queue);
int ft_calcul_score(int ants, int verteces, int path_number);
int ft_bfs(t_parse *prs, int flow);
void ft_print_visited(int *visited, int size); // TO DELETE
// t_parse *getset(t_parse *g);
void ft_manage_path(t_parse *prs);
int *ft_strdup_int(int *s1, int start, int size);
int ft_strdel_int(int **as);
int ft_strequ_int(int *s1, int *s2, int size);
t_list_node *ft_get_node(t_list_node *list, int vertex);
void ft_block_path(t_parse *prs, int *tab);
void ft_store_path_in_group(t_parse *prs, int *path, int path_length, t_groups **store_path, t_groups **last_grp_ptr);
void print_groups(t_parse *prs);		// to del
void printArray(int array[], int size); // to delete
void send_ants(t_parse *prs);
void ft_balance_paths(t_parse *prs, t_groups *group, int best_score_path_id);
void ft_rescue_memory(t_parse *prs);
int		get_next(const int fd, char **line, t_parse *prs);
#endif
