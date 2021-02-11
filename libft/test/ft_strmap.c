/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:55:48 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/16 17:45:33 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
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
		new_string[i] = f(s[i]);
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

char ff(char c)
{
	return (c + 1);
}

//char (*f)(char) = ff;

int main()
{
	char s[4] = "abc";	

	char *x;
   	x = ft_strmap(s, ff);
	int i = 0;
	while (x[i])
		printf("%c",x[i++]);	

}
