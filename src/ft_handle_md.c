/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_md.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 03:04:23 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 10:13:32 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_md(t_flag *flag, va_list *args)
{
	intmax_t	res;

	if (flag->c[0] == 1)
		res = (intmax_t)(char)va_arg(*args, long int);
	else if (flag->c[1] == 1)
		res = (intmax_t)(short)va_arg(*args, long int);
	else if (flag->c[2] == 1 || flag->c[3] == 1)
		res = (intmax_t)va_arg(*args, long long int);
	else if (flag->c[4] == 1)
		res = va_arg(*args, intmax_t);
	else if (flag->c[5] == 1)
		res = (intmax_t)va_arg(*args, size_t);
	else
		res = va_arg(*args, long);
	res = ft_unsign(res, flag);
	if (res == 0)
		return (ft_strnull(res));
	return (ft_itoa_base(res, 10, flag));
}

int		ft_handle_md(const char *format, va_list *args, t_flag *flag)
{
	char	*res;
	int		len;

	res = ft_md(flag, args);
	if (flag->pr != -1)
		res = ft_apply_pre_d(res, flag);
	res = ft_mini_field(res, flag);
	if (flag->p >= 1)
		res = ft_apply_p(res);
	if (flag->s >= 1 && flag->p == 0)
		res = ft_apply_s(res);
	if (flag->z >= 1 && flag->m == 0)
		ft_apply_z(res, flag);
	ft_putstr(res);
	len = ft_strlen(res);
	free(res);
	return (len);
}
