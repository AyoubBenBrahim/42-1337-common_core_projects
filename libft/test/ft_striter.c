/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:59:54 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/16 17:44:40 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void f(char *c)
{
	*c = *c + 1;
}
//void	(*f)(char *) = fa;

void	ft_striter(char *s, void (*f)(char *))
{
	while (*s)
		f(s++);
}

int main()
{
	char s[4] = "123";
	ft_striter(s, &f);
	int i = 0;
	while (s[i])
		printf("%c",s[i++]);

 	return 0;
}
