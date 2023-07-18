/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 00:50:12 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/22 18:16:26 by ayb*****         ###   ########.fr       */
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

	bool = (c == ' ' || c == '\n' || c == '\t') ? 1 : 0;
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
	else if (str[index] == '+')
	{
		sign = 1;
		index++;
	}
	result = ascii_to_int(str, index);
	return (result * sign);
}
