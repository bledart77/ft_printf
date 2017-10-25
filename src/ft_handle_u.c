/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 02:53:49 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 10:36:11 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_u(t_flag *flag, va_list *args)
{
	intmax_t		res;
	char			*str;

	if (flag->c[0] == 1)
		res = (uintmax_t)(unsigned char)va_arg(*args, unsigned int);
	else if (flag->c[1] == 1)
		res = (uintmax_t)(unsigned short)va_arg(*args, unsigned int);
	else if (flag->c[2] == 1)
		res = (uintmax_t)va_arg(*args, unsigned long);
	else if (flag->c[3] == 1)
		res = (uintmax_t)va_arg(*args, unsigned long long);
	else if (flag->c[4] == 1)
		res = va_arg(*args, uintmax_t);
	else if (flag->c[5] == 1)
		res = (uintmax_t)va_arg(*args, size_t);
	else
		res = (uintmax_t)va_arg(*args, unsigned int);
	if (res == 0)
		return (ft_strnull(res));
	return (ft_itoa_base(res, 10, flag));
}

int		ft_handle_u(const char *format, va_list *args, t_flag *flag)
{
	int		len;
	char	*res;

	res = ft_u(flag, args);
	if (flag->pr != -1)
		res = ft_apply_pre_d(res, flag);
	res = ft_mini_field(res, flag);
	if (flag->z >= 1 && flag->m == 0)
		ft_apply_z(res, flag);
	if (flag->pr == 0)
	{
		free(res);
		return (ft_dispblank(flag->t));
	}
	ft_putstr(res);
	len = ft_strlen(res);
	free(res);
	return (len);
}
