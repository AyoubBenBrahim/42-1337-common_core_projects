/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:31:38 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/22 18:27:52 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
/*
char *test_pointer(void *p)
{
	if (p == NULL)
		return ("pointer is NULL");
	else
		return ("pointer is not NULL");

}

int main()
{
	void	*p;

	p = malloc(sizeof(*p) * 12);
	printf("before memdel : %s\n", test_pointer(p));
	ft_memdel(&p);
	printf("after calling memdel : %s\n", test_pointer(p));
}
*/
