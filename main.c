#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{
	int		ret1;
	int		ret2;
/*
	n = printf("Hello\n");
	printf("%d\n\n", n);
*/

/*
	n = ft_printf("Hello %s %% %c 42\n");
	printf("%d\n\n", n);
*/

/* в чаре и проценте точность не применяется */
	ret1 = printf("hello %c hi\n", 'u');
	ret2 = ft_printf("hello %c hi\n", 'u');
	printf("orig %d my %d\n", ret1, ret2);
/*
	printf("hello %c hi\n", 'h');
	ft_printf("hello %c hi\n", 'h');
*/
//	ft_printf("hello %c hi %%|\n", 'u');

/*
	printf("str is %s\n", "hello");
	ft_printf("str is %s\n", "hello");
	printf("|%21s|\n", "cat");
	printf("|%-021s|\n", "cat");
	printf("|%*s|\n", -21, "cat");
	printf("|%-*s|\n", 21, "cat");
*/
}
