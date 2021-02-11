/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:55:48 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/14 16:47:12 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_string;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	new_string = NULL;
	new_string = (char *)malloc(ft_strlen(s) + 1);
	if (new_string == NULL)
		return (NULL);
	while (s[i])
	{
		new_string[i] = f(s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
