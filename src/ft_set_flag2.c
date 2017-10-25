/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_flag2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:15:55 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 11:03:17 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int			ft_set_pre(const char *format, t_flag *flag)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(11);
	if (ft_isdigit(*format))
	{
		while (ft_isdigit(*format))
		{
			res[i] = *format;
			format++;
			i++;
		}
	}
	res[i] = '\0';
	flag->pr = ft_atoi(res);
	if (i == 0)
		flag->pr = 0;
	free(res);
	return (i);
}

void		ft_set_lengthmo(const char *format, t_flag *flag)
{
	if (ft_is_handle(format[1]) == 0)
	{
		if (*format == 'h' && format[1] == 'h')
			flag->c[0] = 1;
		else
			flag->c[3] = 1;
	}
	else
	{
		if (*format == 'h')
			flag->c[1] = 1;
		else if (*format == 'l')
			flag->c[2] = 1;
		else if (*format == 'j')
			flag->c[4] = 1;
		else if (*format == 'z')
			flag->c[5] = 1;
	}
}

void		ft_len(const char *format)
{
	while (ft_is_handle(*format) == 0)
		format++;
}

uintmax_t		ft_unsign(intmax_t res, t_flag *flag)
{
	flag->sign = '+';
	if (res < 0)
	{
		flag->sign = '-';
		res = -res;
	}
	return ((uintmax_t)res);
}
