/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 10:34:20 by ayb*****          #+#    #+#             */
/*   Updated: 2020/11/05 10:34:22 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	**create_map(int size, t_mem *mem)
{
	t_link	**map;
	int		i;

	map = ft_malloc((sizeof(t_link*) * size), mem);
	i = 0;
	while (i < size)
	{
		map[i] = ft_malloc((sizeof(t_link) * size), mem);
		i++;
	}
	return (map);
}
