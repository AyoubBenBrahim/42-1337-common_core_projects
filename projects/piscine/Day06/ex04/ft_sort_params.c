/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 10:12:02 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/25 03:27:35 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	bubble_sort(int size, char **strings)
{
	int		index;
	int		new_size;
	int		in_desordrer;
	char	*temp;

	in_desordrer = 1;
	new_size = size;
	while (in_desordrer)
	{
		in_desordrer = 0;
		index = 0;
		while (index < new_size - 1)
		{
			if (ft_strcmp(strings[index], strings[index + 1]) >= 1)
			{
				temp = strings[index];
				strings[index] = strings[index + 1];
				strings[index + 1] = temp;
				in_desordrer = 1;
			}
			index++;
		}
		new_size--;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		size;
	char	*strings[argc - 1];

	size = argc - 1;
	i = 0;
	while (i < argc)
	{
		strings[i] = argv[i + 1];
		i++;
	}
	bubble_sort(size, strings);
	i = 0;
	while (i < argc - 1)
	{
		ft_putstr(strings[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
