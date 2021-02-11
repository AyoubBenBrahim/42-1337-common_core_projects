/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:58:02 by ahel-men          #+#    #+#             */
/*   Updated: 2019/07/20 21:45:39 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		check_empty_file(char **av)
{
	char		buffer[4];
	int			fd;

	fd = open(av[1], O_RDONLY);
	if (read(fd, buffer, 4) == 0)
	{
		ft_putendl("empty file !");
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int		manage_errors(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("Usage : ./fdf <filename>\n");
		return (0);
	}
	if (av[1][strlen(av[1]) - 1] == 'f' && av[1][strlen(av[1]) - 2] == 'd'
		&& av[1][strlen(av[1]) - 3] == 'f' && av[1][strlen(av[1]) - 4] == '.')
		return (1);
	else
	{
		ft_putendl("Error : not a valid name");
		return (0);
	}
}

int		check_fd(int fd)
{
	if (fd < 0)
	{
		ft_putendl("Error : not a valid name or access rights problem !");
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_option	*option;
	t_list2		*list;
	int			fd;

	if (!manage_errors(ac, av))
		return (0);
	if (!check_empty_file(av))
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!check_fd(fd))
		return (0);
	if (!(option = (t_option *)ft_memalloc(sizeof(t_option))))
		return (0);
	option->mlx = mlx_init();
	option->win = mlx_new_window(option->mlx, 800, 800, "FDF");
	ft_option_init(option, option->mlx, option->win);
	if (!(list = read_file(fd, option)))
		return (0);
	option->head = list;
	mlx_hook(option->win, 2, 0, key_press, option);
	mlx_hook(option->win, 4, 0, mouse_press, option);
	mlx_loop(option->mlx);
	close(fd);
	return (0);
}
