/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 09:39:15 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 10:49:44 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <wchar.h>
# include <stdio.h>
# include <locale.h>
# include <limits.h>

typedef struct	s_flag
{
	int		s;
	int		d;
	int		z;
	int		m;
	int		p;
	int		t;
	int		pr;
	int		c[6]; // hh h l ll j  z
	char	h;
	char	sign;
}				t_flag;

// lib

int				ft_atoi(const char *str);
long long int	ft_atoi_l_l(const char *str);
int				ft_intlen(int nb);
int				ft_long_intlen(long int nb);
void			ft_putchar(char c);
int				ft_isdigit(int c);
char			*ft_itoa_base_next_level(int nb, char *base);
char			*ft_itoa_b_n_l_u(long long int nb, char *base, int nb_byte);
char			*ft_itoa_base_next_level_long(long int nb, char *base);
char			*ft_itoa_b_n_l_intmax(intmax_t nb, char *base);
char			*ft_itoa(int nb);
char			*ft_itoa_base(intmax_t, int nb, t_flag *flag);
char			*ft_itoa_hexa(int nb);
long int		ft_power(long int nb, int pow);
void			ft_putstr(const char *str);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcatc(char *dest, const char c);
char			*ft_strcatcat(char *s1, char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_strlen(const char *str);
char			*ft_strrev(char *str);

// ft_printf.c

int				ft_printf(const char *format, ...);
int				ft_display(const char *format, va_list *args, t_flag *flag);
int				ft_display2(const char *format, va_list *args, t_flag *flag);

// ft_apply_pre.c

char			*ft_inistr(char *ext, int b);
char			*ft_polym(char *res, char *ext);
char			*ft_apply_pre_d(char *res, t_flag *flag);
char			*ft_apply_pre_s(char *res, t_flag *flag);

// ft_mini_field.c

char			*ft_field_null(t_flag *flag);
char			*ft_mini_field(char *res, t_flag *flag);

// ft_handle.c

int				ft_handle_c(const char *format, va_list *args, t_flag *flag);

// ft_handle_d.c

char			*ft_d(t_flag *flag, va_list *args);
int				ft_handle_d(const char *format, va_list *args, t_flag *flag);

// ft_handle_p.c

char			*ft_pointer(const char *format, va_list *args);
int				ft_handle_p(const char *format, va_list *args, t_flag *flag);

// ft_handle_s.c

int				ft_handle_s(const char *format, va_list *args, t_flag *flag);

// ft_int_to_char

char			*ft_int_to_char(int nb);
char			*ft_int_to_char_unsigned(long int nb, int nb_byte);
char			*ft_int_to_char_long(long int nb);

// ft_set_flag.c

int				ft_ini(t_flag *flag);
int				ft_is_handle(char c);
void			ft_set_option_flag(char c, t_flag *flag);
int				ft_set_ta(const char *format, t_flag *flag);
int				ft_set_flag(const char *format, t_flag *flag);

// ft_set_flag2.c

int				ft_set_pre(const char *format, t_flag *flag);
void			ft_set_lengthmo(const char *format, t_flag *flag);
void			ft_len(const char *format);
uintmax_t		ft_unsign(intmax_t res, t_flag *flag);

// ft_handle_flag.c

void			ft_apply_m(char *str);
char			*ft_apply_p(char *str);
char			*ft_apply_s(char *str);
void			ft_apply_z(char *str, t_flag *flag);
int				ft_dispblank(int n);

// ft_apply_d.c

char			*ft_apply_do(char *str, t_flag *flag);
char			*ft_apply_dx(char *str, t_flag *flag);

// ft_handle_md.c

char			*ft_md(t_flag *flag, va_list *args);
int				ft_handle_md(const char *format, va_list *args, t_flag *flag);

// ft_handle_x.c

char			*ft_x(t_flag *flag, va_list *args);
char			*ft_handle_x_ext(char *res, t_flag *flag);
int				ft_handle_x(const char *format, va_list *args, t_flag *flag);

// ft_handle_mo.c

char			*ft_strnull(intmax_t nb);
char			*ft_mo(t_flag *flag, va_list *args);
int				ft_handle_mo(const char *format, va_list *args, t_flag *flag);

// ft_handle_o.c

int				ft_handle_o(const char *format, va_list *args, t_flag *flag);

// ft_handle_u.c

char			*ft_u(t_flag *flag, va_list *args);
int				ft_handle_u(const char *format, va_list *args, t_flag *flag);

// ft_handle_mu.c

char			*ft_mu(t_flag *flag, va_list *args);
int				ft_handle_mu(const char *format, va_list *args, t_flag *flag);

// ft_handle_mc.c

int				ft_handle_mc(const char *format, va_list *args, t_flag *flag);
int				ft_7bitchar(char *str);
int				ft_11bitchar(char *str);
int				ft_16bitchar(char *str);
int				ft_bitchar(char *str);

// ft_wchar.c

char			*ft_complete(char *str, int n);
int				ft_dec(char *str);
char			*ft_extract(char *str, int start, int end);

// ft_handle_ms.c

int				ft_handle_ms(const char *format, va_list *args, t_flag *flag);
int				ft_disp(wchar_t c);

// ft_handle_percent.c

int				ft_handle_percent(t_flag *flag);

// ft_check.c

int				ft_check(char *str, t_flag *flag);

#endif
