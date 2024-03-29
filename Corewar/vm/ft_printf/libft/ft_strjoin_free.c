/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:56:39 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/24 19:47:35 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_strjoin_free(char *s1, char *s2)
{
	size_t		i;
	char		*joined;

	if (!s1 || !s2)
		return (NULL);
	i = pf_strlen(s1) + pf_strlen(s2);
	if (!(joined = pf_strnew(i)))
		return (NULL);
	pf_strcpy(joined, s1);
	pf_strcat(joined, s2);
	free(s1);
	free(s2);
	return (joined);
}
