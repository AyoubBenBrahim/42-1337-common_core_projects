/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:20:38 by ahel-men          #+#    #+#             */
/*   Updated: 2019/05/31 15:57:57 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			manage_errors(t_list2 *list, int fd1, int fd2, int flag)
{
	char	buffer[4];

	if (flag == 1 && (read(fd1, buffer, 4) == 0))
	{
		ft_putendl("error");
		close(fd1);
		return (0);
	}
	if (flag == 2)
	{
		if (!list || (fd2 < 0 && close(fd2)))
		{
			ft_putendl("error");
			return (0);
		}
	}
	return (1);
}
