/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 08:33:17 by ayb*****          #+#    #+#             */
/*   Updated: 2020/10/25 09:31:34 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lem_in.h"

void	start_to_end_directly(t_parse *prs, char **tab, int lenght)
{
	int x;

	if ((!ft_strcmp(prs->start, tab[1]) && !ft_strcmp(prs->end, tab[2]))
			|| (!ft_strcmp(prs->end, tab[1]) && !ft_strcmp(prs->start, tab[2])))
	{
		x = 1;
		while (x <= prs->nbr_ants)
		{
			ft_putchar('L');
			ft_putnbr(x);
			ft_putchar('-');
			ft_putstr(prs->end);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		free_2d(tab, lenght + 1);
		ft_rescue_memory(prs, 0);
		exit(0);
	}
}

void	get_edges(t_parse *prs)
{
	char	**tab;
	int		x;
	int		y;
	int		lenght;

	tab = parse_line(prs, prs->line, '-');
	lenght = (int)ft_atoll(tab[0]);
	start_to_end_directly(prs, tab, lenght);
	x = ft_binary_search(prs, prs->array_of_rooms, tab[1]);
	y = ft_binary_search(prs, prs->array_of_rooms, tab[2]);
	if (x < 0 || y < 0)
	{
		free_2d(tab, lenght + 1);
		ft_rescue_memory(prs, ERROR);
	}
	free_2d(tab, lenght + 1);
	ft_create_link(prs->graph, x, y);
}

char	*get_vertices(t_parse *prs, char *line)
{
	char	**array;
	char	*vertex;
	int		len;

	array = parse_line(prs, line, ' ');
	if (!array || !*array)
	{
		ft_strdel(&line);
		prs->line = ft_strdup("nothing");
		ft_rescue_memory(prs, ERROR);
	}
	if (array[1][0] >= '!' && array[1][0] <= 126)
		fill_lst(&prs->rooms_lst, array);
	prs->total_vertices++;
	len = (int)ft_atoll(array[0]);
	vertex = ft_strdup(array[1]);
	free_2d(array, len + 1);
	return (vertex);
}

/*
*** in graph theory, a vertex (plural vertices) or node is a point
*** where two or more edges (links or lines) meet.
*/

void	get_start_vertex(t_parse *prs)
{
	int		ret;
	char	*ligne;

	if (ft_strlen(prs->line) == 7 && !ft_strncmp(prs->line, "##start", 7))
	{
		if (prs->start_is_set == FALSE)
		{
			while ((ret = get_next(0, &ligne, prs)) > 0 && ligne[0] == '#')
			{
				if (!ft_strncmp(ligne, "##start", 7))
				{
					ft_strdel(&ligne);
					ft_rescue_memory(prs, ERROR);
				}
				ft_strdel(&ligne);
			}
			prs->start = get_vertices(prs, ligne);
			prs->start_is_set = TRUE;
			ft_strdel(&ligne);
		}
		else
			ft_rescue_memory(prs, ERROR);
	}
}

void	get_end_vertex(t_parse *prs)
{
	int		ret;
	char	*ligne;

	if (ft_strlen(prs->line) == 5 && !ft_strncmp(prs->line, "##end", 5))
	{
		if (prs->end_is_set == FALSE)
		{
			while ((ret = get_next(0, &ligne, prs)) > 0 && ligne[0] == '#')
			{
				if (!ft_strncmp(ligne, "##end", 5))
				{
					ft_strdel(&ligne);
					ft_rescue_memory(prs, ERROR);
				}
				ft_strdel(&ligne);
			}
			prs->end = get_vertices(prs, ligne);
			prs->end_is_set = TRUE;
			ft_strdel(&ligne);
		}
		else
			ft_rescue_memory(prs, ERROR);
	}
}

void	store_start_end_index(t_parse *prs)
{
	prs->start_index = ft_binary_search(prs, prs->array_of_rooms, prs->start);
	prs->end_index = ft_binary_search(prs, prs->array_of_rooms, prs->end);
}

void	no_start_end_error(t_parse *prs)
{
	if (!prs->start_is_set || !prs->end_is_set)
		ft_rescue_memory(prs, ERROR);
}

void	isolated_start_end_error(t_parse *prs)
{
	if (!prs->graph->tab[prs->start_index].list
		|| !prs->graph->tab[prs->end_index].list)
		ft_rescue_memory(prs, ERROR);
}

int		get_ants(t_parse *prs)
{
	int ret;

	ret = get_next(0, &prs->line, prs);
	if (ret > 0 && prs->line[0] == '#' && prs->line[1] != '#')
	{
		ft_strdel(&prs->line);
		return (get_ants(prs));
	}
	else if (ret > 0 && is_number(prs->line)
			&& (prs->nbr_ants = ft_atoll(prs->line)) > 0)
	{
		ft_strdel(&prs->line);
		return (1);
	}
	ft_rescue_memory(prs, ERROR);
	return (0);
}

void	rooms(t_parse *prs)
{
	int		ret;
	char	*array;

	while ((ret = get_next(0, &prs->line, prs)) > 0)
	{
		if (ft_strstr(prs->line, "-"))
		{
			prs->line_tmp = ft_strdup(prs->line);
			ft_strdel(&prs->line);
			return ;
		}
		if (prs->line[0] == '#' && prs->line[1] == '#')
		{
			get_start_vertex(prs);
			get_end_vertex(prs);
		}
		else if (prs->line[0] == '#' && prs->line[1] != '#')
			ft_strdel(&prs->line);
		else
		{
			array = get_vertices(prs, prs->line);
			ft_strdel(&array);
		}
		ft_strdel(&prs->line);
	}
}

void	links(t_parse *prs)
{
	int ret;

	ret = 0;
	prs->line = ft_strdup(prs->line_tmp);
	ft_strdel(&prs->line_tmp);
	get_edges(prs);
	ft_strdel(&prs->line);
	while ((ret = get_next(0, &prs->line, prs)))
	{
		if (!ft_strncmp(prs->line, "##end", 5)
				|| !ft_strncmp(prs->line, "##start", 7))
			ft_rescue_memory(prs, ERROR);
		if (prs->line[0] != '#')
			get_edges(prs);
		ft_strdel(&prs->line);
	}
}


void init_debug(const char *file){
 int fd = open(file, O_RDONLY);
 dup2(fd, 0);
}

int		main(int ac, char **av)
{
	t_parse prs;


// 	FILE *fp = fopen ("/dev/ttys005", "w+");
//    fprintf(fp, "\n%s %s %s %d\n", "We", "are", "in", 2012);
//    fprintf(fp, "\n%s %s %s %d\n", "We", "are", "in", 2012);
//    fclose(fp);
//    exiter
init_debug(av[1]);

	ft_memset((void *)&prs, 0, sizeof(t_parse));
	prs.start_is_set = FALSE;
	prs.end_is_set = FALSE;

	// prs.is_intersection = FALSE;
	prs.group_id = 1;
	get_ants(&prs);
	rooms(&prs);
	no_start_end_error(&prs);
	merge_sort(&prs, &prs.rooms_lst);
	lst_2array(&prs);
	// printf("create graph\n");
	prs.graph = ft_create_graph(prs.total_vertices);
	// printf("links\n");
	links(&prs);
	// printf("after links\n");
	store_start_end_index(&prs);
	isolated_start_end_error(&prs);
	// printf("count_adjs\n");
	// count_adjs(&prs);
	// printf("print_graph\n");
// 	print_graph(&prs);
// exiter
	// dfs(&prs);

	// fitox(&prs);

	// print_adj_addr(&prs);
// exiter

	ant_eater(&prs);

	// print_graph(&prs);
exiter


	// ft_manage_path(&prs);


	if (prs.there_is_intersection)
		re_groupe(&prs);
	calc_score(&prs);

 printf("\n\n====G====\n");


print_this_group(&prs, prs.best_score_grp);
exiter

// groups2(&prs);
// exiter

	print_groups(&prs);

	// printf("\n\nSCORE = %d\n", prs.smallest_score);
    // printf("\ngroup = %d\n", prs.best_score_grp->group_id);

exiter

	send_ants(&prs);
	ft_rescue_memory(&prs, 0);
	return (0);
}
