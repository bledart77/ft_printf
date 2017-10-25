/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:57:27 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 10:11:50 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_ini(t_flag *flag)
{
	flag->s = 0;
	flag->d = 0;
	flag->z = 0;
	flag->m = 0;
	flag->p = 0;
	flag->t = 0;
	flag->pr = -1;
	flag->c[0] = 0;
	flag->c[1] = 0;
	flag->c[2] = 0;
	flag->c[3] = 0;
	flag->c[4] = 0;
	flag->c[5] = 0;
	flag->h = 'v';
	flag->sign = '0';
	return (0);
}

int		ft_is_handle(char c)
{
	if (c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'd' || c == 'D'
			|| c == 'i' || c == 's' || c == 'S' || c == 'c' || c == 'C' ||
				c == '%' || c == 'p' || c == 'o' || c == 'O')
		return (1);
	return (0);
}

void	ft_set_option_flag(char c, t_flag *flag)
{
	if (c == ' ')
		flag->s++;
	if (c == '#')
		flag->d++;
	if (c == '0')
		flag->z++;
	if (c == '-')
		flag->m++;
	if (c == '+')
		flag->p++;
}

int		ft_set_ta(const char *format, t_flag *flag)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(ft_strlen(format) + 1);
	while (ft_isdigit(*format))
	{
		res[i] = *format;
		format++;
		i++;
	}
	res[i] = '\0';
	flag->t = ft_atoi(res);
	return (i);
}

int		ft_set_flag(const char *format, t_flag *flag)
{
	int		i;

	i = 0;
	while (*format == ' ' || *format == '#' || *format == '0' ||
			*format == '-' || *format == '+')
	{
		ft_set_option_flag(*format, flag);
		format++;
	}
	if (ft_isdigit(*format) == 1)
		format = format + ft_set_ta(format, flag);
	if (*format == '.')
	{
		format++;
		format = format + ft_set_pre(format, flag);
	}
	if (ft_is_handle(*format) == 0)
		ft_set_lengthmo(format, flag);
	while (ft_is_handle(*format) != 1)
		format++;
	flag->h = *format;
	return (ft_check((char*)format, flag));
}
