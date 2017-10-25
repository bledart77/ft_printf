/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 01:16:21 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 10:00:34 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_strnull(intmax_t nb)
{
	char	*res;

	nb = 0;
	res = malloc(2);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char	*ft_mo(t_flag *flag, va_list *args)
{
	intmax_t		res;

	if (flag->c[0] == 1)
		res = (uintmax_t)va_arg(*args, unsigned int);
	else if (flag->c[1] == 1)
		res = (uintmax_t)(short)va_arg(*args, unsigned int);
	else if (flag->c[2] == 1 || flag->c[3] == 1)
		res = (uintmax_t)va_arg(*args, unsigned  long);
	else if (flag->c[4] == 1)
		res = va_arg(*args, uintmax_t);
	else if (flag->c[5] == 1)
		res = (uintmax_t)va_arg(*args, size_t);
	else
		res = (uintmax_t)va_arg(*args, unsigned long);
	if (res == 0)
		return (ft_strnull(res));
	return (ft_itoa_base(res, 8, flag));
}

int		ft_handle_mo(const char *format, va_list *args, t_flag *flag)
{
	int		len;
	char	*res;

	res = ft_mo(flag, args);
	if (flag->pr != -1)
		res = ft_apply_pre_d(res, flag);
	res = ft_mini_field(res, flag);
	if (flag->d >= 1)
		res = ft_apply_do(res, flag);
	if (flag->z >= 1 && flag->m == 0)
		ft_apply_z(res, flag);
	ft_putstr(res);
	len = ft_strlen(res);
	free(res);
	return (len);
}
