/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 17:39:44 by ayb*****          #+#    #+#             */
/*   Updated: 2019/01/17 23:39:28 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_arrays(int am[], int pm[])
{
	am[0] = 1;
	am[1] = 2;
	am[2] = 3;
	am[3] = 4;
	am[4] = 5;
	am[5] = 6;
	am[6] = 7;
	am[7] = 8;
	am[8] = 9;
	pm[0] = 13;
	pm[1] = 14;
	pm[2] = 15;
	pm[3] = 16;
	pm[4] = 17;
	pm[5] = 18;
	pm[6] = 19;
	pm[7] = 20;
	pm[8] = 21;
	pm[9] = 22;
}

void	hour_is_pm(int hour)
{
	int a;
	int converted;
	int pm[10];
	int am[9];

	converted = hour % 12;
	fill_arrays(am, pm);
	a = 0;
	while (a < 10)
	{
		if (pm[a] == hour)
		{
			printf("%d.00 P.M. AND %d.00 P.M.\n", converted, converted + 1);
		}
		a++;
	}
}

void	hour_is_am(int hour)
{
	int a;
	int pm[10];
	int am[9];

	fill_arrays(am, pm);
	a = 0;
	while (a < 9)
	{
		if (am[a] == hour)
		{
			if (am[a] == 9)
			{
				printf("0%d.00 A.M. AND 10.00 A.M.\n", am[a]);
			}
			else
			{
				printf("0%d.00 A.M. AND 0%d.00 A.M.\n", am[a], am[a] + 1);
			}
		}
		a++;
	}
}

void	ft_takes_place(int hour)
{
	int converted;

	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	hour_is_pm(hour);
	if (hour == 0 || hour == 12)
		(hour == 12) ?
		printf("12.00 P.M. AND 01.00 P.M.\n") :
		printf("12.00 A.M. AND 01.00 A.M.\n");
	if (hour == 23)
		printf("11 P.M. AND 12.00 A.M.\n");
	if (hour == 10)
		printf("10 A.M. AND 11.00 A.M.\n");
	if (hour == 11)
		printf("11 A.M. AND 12.00 P.M.\n");
	hour_is_am(hour);
}
