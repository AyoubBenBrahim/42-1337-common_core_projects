/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:50:50 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/16 17:48:27 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	int		i;

	i = 0;
	new_string = NULL;
	new_string = (char *)malloc(strlen(s) + 1);
	if (new_string == NULL)
		return (NULL);
	while (s[i])
	{
		new_string[i] = f(i, s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char f(unsigned int i, char c)
{
	i = 1;
	return (c + i);
}

//char (*f)(unsigned int, char) = ff;

int main()
{
	char s[4] = "123";

	char *x;
	x = ft_strmapi(s, f);
	int i = 0;
	while (x[i])
		printf("%c",x[i++]);
}
