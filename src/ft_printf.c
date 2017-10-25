/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 00:28:35 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/23 17:54:51 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_printf(const char *format, ...)
{
	int			res;
	va_list		args;
	t_flag		flag;

	res = ft_ini(&flag);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_set_flag(format, &flag) == 0)
				return (-1);
			res += ft_display(format, &args, &flag);
			while (ft_is_handle(*format) != 1)
				format++;
			format++;
		}
		else
		{
			ft_putchar(*format++);
			res++;
		}
	}
	return (res);
}

int		ft_display(const char *format, va_list *args, t_flag *flag)
{
	if (flag->h == 's')
		return (ft_handle_s(format, args, flag));
	else if (flag->h == 'S')
		return (ft_handle_ms(format, args, flag));
	else if (flag->h == 'p')
		return (ft_handle_p(format, args, flag));
	else if (flag->h == 'd' || flag->h == 'i')
		return (ft_handle_d(format, args, flag));
	else if (flag->h == 'D')
		return (ft_handle_md(format, args, flag));
	else if (flag->h == 'o')
		return (ft_handle_o(format, args, flag));
	else if (flag->h == 'O')
		return (ft_handle_mo(format, args, flag));
	else if (flag->h == 'u')
		return (ft_handle_u(format, args, flag));
	else if (flag->h == 'U')
		return (ft_handle_mu(format, args, flag));
	else if (flag->h == 'x' || flag->h == 'X')
		return (ft_handle_x(format, args, flag));
	else
		return (ft_display2(format, args, flag));
}

int		ft_display2(const char *format, va_list *args, t_flag *flag)
{
	if (flag->h == 'c')
		return (ft_handle_c(format, args, flag));
	else if (flag->h == 'C')
		return (ft_handle_mc(format, args, flag));
	else if (flag->h == '%')
		return(ft_handle_percent(flag));
	else
		return (0);
}
