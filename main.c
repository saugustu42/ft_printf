#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	int		n;

	n = printf("Hello\n");
	printf("%d\n\n", n);

	n = ft_printf("Hello %s %% %c 42\n");
	printf("%d\n\n", n);
}