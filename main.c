#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	int		n;

	n = printf("Hello\n");
	printf("%d\n\n", n);

/*
	n = ft_printf("Hello %s %% %c 42\n");
	printf("%d\n\n", n);
*/

	printf("hello %c hi %%|\n", 'u');
	ft_printf("hello %c hi %%|\n", 'u');

	printf("str is %s\n", "hello");
	ft_printf("str is %s\n", "hello");
}
