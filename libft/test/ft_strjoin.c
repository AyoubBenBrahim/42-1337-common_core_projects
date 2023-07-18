/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 10:48:28 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/17 13:33:59 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*joined;
	size_t		i;

	if (!s1)
		return (NULL);
	i = 0;
	joined = (char *)malloc(strlen(s1) + strlen(s2) + 1);
	if (joined == NULL)
		return (NULL);
	while (*s1)
	{
		joined[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		joined[i] = *s2;
		s2++;
		i++;
	}
	joined[i] = '\0';
	return (joined);
}

int main()
{
	printf("%s\n",ft_strjoin("123abcde","xyz123456"));
}
