#include <unistd.h>
#include <stdlib.h>

#define IS_SPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\n')
#define IS_END_LINE(c) ((c) == '\0')

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_wd_ct(char *str)
{
	int wd_ct;

	wd_ct = 0;
	while (*str)
	{
		while (IS_SPACE(*str))
			str++;
		if (!IS_SPACE(*str) && !IS_END_LINE(*str))
			wd_ct++;
		while (!IS_SPACE(*str) && !IS_END_LINE(*str))
			str++;
	}
	return (wd_ct);
}

int	ft_lt_ct(char *str)
{
	int lt_ct;

	lt_ct = 0;
	while (!IS_SPACE(*str) && !IS_END_LINE(*str))
	{
		lt_ct++;
		str++;
	}
	return (lt_ct);
}

void	ft_print_rev(char **word)
{
	while (*word != NULL)
	{
		while (**word != '\0')
		{
			ft_putchar(**word);
			(*word)++;
		}
		if (*(++word) != NULL)
			ft_putchar(' ');
	}
}

char	**ft_split_and_rev(char *str)
{
	char	**word;
	int	wd_ct;
	int	tmp;

	wd_ct = 0;
	wd_ct = ft_wd_ct(str);
	word = (char**)malloc(sizeof(*word) * (wd_ct + 1));
	word[wd_ct] = NULL;
	while (*str && wd_ct >= 0)
	{
		tmp = 0;
		wd_ct--;
		while (IS_SPACE(*str))
			str++;
		word[wd_ct] = (char*)malloc(sizeof(**word) * (ft_lt_ct(str) + 1));
		while (!IS_SPACE(*str) && !IS_END_LINE(*str))
		{
			word[wd_ct][tmp] = *str;
			str++;
			tmp++;
		}
		word[wd_ct][tmp] = '\0';
	}
	ft_print_rev(word);
	ft_putchar('\n');
	return (word);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && argv[1] != '\0')
		ft_split_and_rev(argv[1]);
	else
		ft_putchar('\n');
	return (0);
}
