/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 09:59:49 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/23 20:09:24 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha(char c)
{
	if ((c < 'a' || c > 'z') &&
			(c < 'A' || c > 'Z'))
		return (0);
	else
		return (1);
}

int		is_numeric(char c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}

void	captalize_after_non_alphabet(char *str, int size)
{
	int i;

	i = 0;
	if (str[0] != '\0')
	{
		if (str[0] >= 'a' && str[0] <= 'z')
			str[0] = str[i] - 32;
	}
	while (i < size - 1)
	{
		if (!is_alpha(str[i]) && !is_numeric(str[i]))
		{
			if (is_alpha(str[i + 1]))
				str[i + 1] = str[i + 1] - 32;
		}
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		i++;
		size++;
	}
	captalize_after_non_alphabet(str, size);
	return (str);
}
