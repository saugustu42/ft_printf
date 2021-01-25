#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	for (int i = 0; i < 5000; i++)
	{
		ft_printf("%c\n", 'a');
		ft_printf("%s\n", "hello");
		ft_printf("%u\n", 42);
		ft_printf("%d\n", 42);
		ft_printf("%x\n", 42);
		ft_printf("%X\n", 42);
		ft_printf("%p\n", &i);
	}
}
