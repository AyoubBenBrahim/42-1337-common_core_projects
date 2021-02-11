/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 22:13:32 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/15 22:23:30 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strrev(char *str)
{
	int		index;
	int		size;
	char	temp;

	index = 0;
	size = 0;
	while (str[index] != '\0')
	{
		size++;
		index++;
	}
	size--;
	index = 0;
	while (index < size)
	{
		temp = str[size];
		str[size] = str[index];
		str[index] = temp;
		index++;
		size--;
	}
	return (str);
}
