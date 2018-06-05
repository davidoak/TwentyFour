#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_inter(char *str1, char *str2, int *asc)
{
	while (*str2)
		asc[(int)(*(str2++))] = 1;
	while (*str1)
	{
		if (asc[(int)(*str1)] == 1)
		{
			ft_putchar(*str1);
			asc[(int)(*str1)] = 2;
		}
		str1++;
	}
	ft_putchar('\n');
}

int	main(int argc, char **argv)
{
	int	asc[128];

	if (argc == 3)
		ft_inter(argv[1], argv[2], asc);
	else
		ft_putchar('\n');
	return (0);
}
