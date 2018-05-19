#include <unistd.h>

void  ft_putchar(char c)
{
  write(1, &c, 1);
}

void  ft_putstr(char *str)
{
  while(*str != '\0')
  {
    ft_putchar(*str);
    str++;
  }
}

int   main()
{
  char *str;

  str = "The function prints the string";
  ft_putstr(str);

  return (0);
}

