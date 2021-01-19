#include <unistd.h>
#include <stdarg.h>

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			dot;
}				t_flags;

int			ft_printf(const char *format, ...);
