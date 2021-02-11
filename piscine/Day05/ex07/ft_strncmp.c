/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:20:03 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/23 17:31:29 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n - 1 && *s1 == *s2)
	{
		if (*s1 == '\0')
			return (*s1 - *s2);
		s1++;
		s2++;
		i++;
	}
	return (*s1 - *s2);
}