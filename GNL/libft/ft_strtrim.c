/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:25:50 by aybouras          #+#    #+#             */
/*   Updated: 2019/04/19 17:34:56 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_whitespace(char c)
{
	return ((c == ' ' || c == '\t' || c == '\n') ? 1 : 0);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s)
		return (NULL);
	i = 0;
	while (is_whitespace(s[i]))
		i++;
	if (s[i] == '\0')
		return (ft_strdup(""));
	start = i;
	i = ft_strlen(s) - 1;
	while (is_whitespace(s[i]))
		i--;
	end = i;
	len = (end - start) + 1;
	return (ft_strsub(s, start, len));
}
