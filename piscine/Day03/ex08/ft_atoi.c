/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:57:47 by aybouras          #+#    #+#             */
/*   Updated: 2019/01/15 19:53:46 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_number(char c)
{
	int bool;

	bool = (c >= '0' && c <= '9') ? 1 : 0;
	return (bool);
}

int	is_space(char c)
{
	int bool;

	bool = (c == ' ' || c == '\n' || c == '\t'
	|| c == '\v' || c == '\f' || c == '\r') ? 1 : 0;
	return (bool);
}

int	ascii_to_int(char *str, int index)
{
	int result;

	result = 0;
	while (is_number(str[index]))
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result);
}

int	ft_atoi(char *str)
{
	int result;
	int sign;
	int index;

	result = 0;
	sign = 1;
	index = 0;
	while (is_space(str[index]))
	{
		index++;
	}
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	if (str[index] == '+')
	{
		sign = 1;
		index++;
	}
	result = ascii_to_int(str, index);
	return (result * sign);
}
