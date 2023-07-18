/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 23:40:58 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/14 15:20:06 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	third_loop(int a, int b, int c)
{
	while (c <= '9')
	{
		if (a == '7' && b == '8' && c == '9')
		{
			ft_putchar(a);
			ft_putchar(b);
			ft_putchar(c);
			c++;
		}
		else
		{
			ft_putchar(a);
			ft_putchar(b);
			ft_putchar(c);
			ft_putchar(',');
			ft_putchar(' ');
			c++;
		}
	}
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '1';
	c = '2';
	while (a <= '7')
	{
		while (b <= '8')
		{
			third_loop(a, b, c);
			b++;
			c = b + 1;
		}
		a++;
		b = a + 1;
		c = b + 1;
	}
}
