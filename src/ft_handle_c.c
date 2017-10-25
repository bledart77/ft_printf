/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 02:22:48 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/06 15:07:29 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_handle_c(const char *format, va_list *args, t_flag *flag)
{
	char	c;
	int		res;
	int		n;

	n = 0;
	res = 1;
	if (flag->t > 1)
		res = flag->t;
	c = va_arg(*args, int);
	if (res == 0)
		ft_putchar(c);
	else if (flag->m != 0)
	{
		ft_putchar(c);
		while (n++ < res - 1)
			ft_putchar(' ');
	}
	else
	{
		while (n++ < res - 1)
			ft_putchar(' ');
		ft_putchar(c);
	}
	return (res);
}
