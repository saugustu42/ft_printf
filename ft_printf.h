/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saugustu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:58:59 by saugustu          #+#    #+#             */
/*   Updated: 2021/01/25 21:27:34 by saugustu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	int			minus;
	int			zero;
	int			width;
	int			dot;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_parser(char **form, int *printed, va_list ap);
void			ft_set_flags(t_flags *flags);
int				ft_save_num(va_list ap, char **form);
int				ft_print_parsed(const char *str, int *printed,
		va_list ap, t_flags *flags);
void			ft_putchar_c(char c, int *printed);
void			ft_putstr_c(char *str, int *printed);
void			ft_putnchar(char c, int *printed, int n);
void			ft_putnstr(char *str, int *printed, int n);
int				ft_print_c(char c, int *printed, t_flags *flags);
int				ft_print_s(char *str, int *printed, t_flags *flags);
int				ft_set_numbers_sig(char *str, int neg, t_flags *flags);
void			ft_put_sig(char *str, int *printed, int neg, t_flags *flags);
int				ft_print_sig(int num, int *printed, t_flags *flags);
char			*ft_conv_pos(unsigned long n, int bs, char c);
void			set_numbers(int len, t_flags *flags);
int				ft_print_u(unsigned int num, int *printed,
		t_flags *flags, char c);
int				ft_print_p(unsigned long num, int *printed, t_flags *flags);
int				ft_set_numbers_sig(char *str, int neg, t_flags *flags);
void			ft_put_sig(char *str, int *printed, int neg, t_flags *flags);
int				ft_print_sig(int num, int *printed, t_flags *flags);

/*
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_isdigit(int c);
*/

#endif
