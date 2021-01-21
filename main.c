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
	printf("orig %d my %d\n\n", ret1, ret2);

	ret1 = printf("hello %s hi\n", "cat");
	ret2 = ft_printf("hello %s hi\n", "cat");
	printf("orig %d my %d\n\n", ret1, ret2);

	ret1 = printf("hello %u hi\n", 4242);
	ret2 = ft_printf("hello %u hi\n", 4242);
	printf("orig %d my %d\n\n", ret1, ret2);

	ret1 = printf("hello %X hi\n", 42);
	ret2 = ft_printf("hello %X hi\n", 42);
	printf("orig %d my %d\n\n", ret1, ret2);

	ret1 = printf("hello %x hi\n", 42);
	ret2 = ft_printf("hello %x hi\n", 42);
	printf("orig %d my %d\n\n", ret1, ret2);

	printf("hello %p hi\n", &ret1);
	ft_printf("hello %p hi\n", &ret1);

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
