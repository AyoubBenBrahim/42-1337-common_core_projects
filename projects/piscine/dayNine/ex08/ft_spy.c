/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 01:09:31 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/18 03:52:54 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_spy(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		i++;
	}
	return ((s1[i] == s2[i]) ? 1 : 0);
}

int		main(int argc, char *argv[])
{
	int		i;
	char	*str1;
	char	*str2;
	char	*str3;

	i = 0;
	str1 = "president";
	str2 = "attack";
	str3 = "Bauer";
	while (i < argc)
	{
		if (is_spy(argv[i], str1) || is_spy(argv[i], str2)
			|| is_spy(argv[i], str3))
			write(1, "Alert!!!\n", 9);
		i++;
	}
}
