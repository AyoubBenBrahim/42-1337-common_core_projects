

#include "libft.h"
#include <stdio.h> // **************** del

static	int		is_alnum(int c)
{
		if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
				|| (c >= 'A' && c <= 'Z') || c == '_')
			return (1);
	return (0);
}

int		is_alpha_num(char *str)
{
	while (*str)
	{
		if (!is_alnum(*str))
			return (0);
		str++;
	}
	return (1);
}
// int main(int ac, char **av)
// {
// 	int i = is_alpha_num(av[1]);

// 	if (i)
// 		printf("ok\n");
// 	else
// 		printf("not ok\n");
// }
