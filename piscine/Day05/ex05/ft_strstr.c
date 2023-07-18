/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 10:28:39 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/22 23:09:03 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		compare(char *str, char *to_find, int i)
{
	int j;

	j = 0;
	while (str[i] && to_find[j])
	{
		if (str[i] != to_find[j])
			return (0);
		i++;
		j++;
	}
	return (to_find[j] == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == to_find[0]) && compare(str, to_find, i))
			return (str + i);
		i++;
	}
	return (0);
}
