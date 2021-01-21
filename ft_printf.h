#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			dot; /* -1 */
}				t_flags;

int			ft_printf(const char *format, ...);

char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
void					*ft_memcpy(void *dst, const void *src, size_t n);

int			ft_isdigit(int c);
void		ft_parcer(const char **form, int *printed, va_list ap);
