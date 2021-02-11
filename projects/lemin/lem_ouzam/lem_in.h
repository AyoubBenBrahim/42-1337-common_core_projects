/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouzamhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 12:59:03 by ouzamhar          #+#    #+#             */
/*   Updated: 2020/11/07 11:56:05 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "libft.h"
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_link	t_link;
typedef struct s_hold	t_hold;
typedef struct s_part	t_part;
typedef	struct s_node	t_node;
typedef	struct s_farm	t_farm;
typedef	struct s_surg	t_surg;
typedef	struct s_queue	t_queue;
typedef	struct s_room	t_room;
typedef	struct s_path	t_path;
typedef	struct s_mem	t_mem;

struct	s_farm
{
	int		ants;
	int		size;
	t_node	*node;
	t_part	*start;
	t_part	*end;
	t_link	**map;
	t_path	*path;
	long	score;
};

struct	s_node
{
	char	*name;
	t_part	*l;
	t_part	*r;
	t_node	*next;
};

struct	s_part
{
	int		idx;
	char	*name;
	t_hold	*adj;
	t_hold	*ladj;
	t_part	*side;
	t_part	*prev;
	t_part	*lprev;
	int		v;
};

struct	s_hold
{
	void	*adr;
	t_hold	*next;
};

struct	s_link
{
	int	c;
	int	f;
};

struct	s_surg
{
	t_part	*prev;
	t_hold	*adj;
	t_surg	*next;
};

struct	s_queue
{
	t_surg	*first;
	t_surg	*end;
	int		v;
};

struct	s_room
{
	char	*name;
	t_room	*prev;
	t_room	*next;
	int		ant;
};

struct	s_path
{
	t_room	*parc;
	int		l;
	int		nb;
	t_room	*end_ptr;
	t_path	*next;
	t_path	*prev;
};

struct	s_mem
{
	t_hold	*hld;
	t_hold	*last;
	t_hold	*line;
	t_hold	*lline;
};

void	read_farm(t_farm *farm, t_mem *mem);
t_hold	*creat_hold(void *adr, t_mem *mem);
void	add_hold(t_hold **lst, t_hold **last, t_hold *new);
long	get_ants(t_mem *mem);
int		get_nodes(t_mem *mem, t_farm *farm);
int		split_node(char *line, int *l, t_mem *mem);
char	*lpart(char *src, int l, t_mem *mem);
int		cmpstr(char *str1, char *str2);
t_part	*creat_part(char *name, int *idx, t_mem *mem);
int		add_node(char *line, t_farm *farm, t_mem *mem);
t_part	*get_part(t_mem *mem, t_farm *farm);
t_link	**create_map(int size, t_mem *mem);
int		get_links(t_mem *mem, t_farm *farm);
void	find_sol(t_farm *farm, t_mem *mem);
int		shortest_path(t_farm *farm, int v, t_mem *mem);
t_surg	*dequeue(t_queue *q);
int		enqueue(t_queue *q, t_part *part, t_mem *mem);
void	augment_flow(t_farm *farm);
t_path	*creat_path(t_farm *farm, t_mem *mem);
long	get_score(t_path *path, long ants);
void	share_ants(t_farm *farm);
void	error(t_mem *mem);
char	*read_line(t_mem *mem);
int		add_mem(t_mem *mem, void *val);
void	free_mem(t_mem *mem);
void	*ft_malloc(size_t size, t_mem *mem);
char	*read_line(t_mem *mem);
void	error(t_mem *mem);
void	start_to_end(t_farm *farm, t_mem *mem);
void	free_lem_in(t_mem *mem);
void	print_lines(t_mem *mem);
void	free_mem(t_mem *mem);
void	printing(t_farm *farm);
void	d_edge(t_part *s, t_part *d, t_farm *farm, t_mem *mem);
void	double_edge(t_node *n1, t_node *n2, t_farm *farm, t_mem *mem);
int		split_link(char *line, t_mem *mem);
t_node	*find_adrr(char *str, t_node *lst, t_mem *mem);
#endif
