/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 01:22:48 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/15 20:28:31 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strrev(char *str)
{
	static		char 	tab[80]
	int			index;
	int			size;
	
	index = 0;
	size = 0;
	while (str[index] != '\0')
	{
		size++;
		index++;
	}
	size--;
	index = 0;
	while (str[index] != '\0')
	{
		tab[size - index] = str[index];
		index++;
	}
	str = tab;
	return (str);
}
