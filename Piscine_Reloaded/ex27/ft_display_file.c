/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:02:11 by aybouras          #+#    #+#             */
/*   Updated: 2019/03/28 18:41:41 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	display_content(int fd)
{
	char	ch;

	while (read(fd, &ch, 1) != 0)
		write(1, &ch, 1);
}

int		main(int argc, char **argv)
{
	int		pointer;

	pointer = -1;
	pointer = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		if (pointer != -1)
		{
			display_content(pointer);
			close(pointer);
		}
	}
	else if (argc == 1)
	{
		write(1, "File name missing.\n", 19);
	}
	else
		write(1, "Too many arguments.\n", 20);
	return (0);
}
