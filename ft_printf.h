#include <unistd.h>
#include <stdarg.h>

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			dot; /* -1 */
}				t_flags;

int			ft_printf(const char *format, ...);
int			ft_isdigit(int c);
void		ft_parcer(const char **form, int *printed, va_list ap);
