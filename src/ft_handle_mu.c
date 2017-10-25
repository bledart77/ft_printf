/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 04:31:07 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 11:04:18 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_mu(t_flag *flag, va_list *args)
{
	intmax_t		res;

	if (flag->c[0] == 1)
		res = (uintmax_t)va_arg(*args, unsigned int);
	else if (flag->c[1] == 1)
		res = (uintmax_t)va_arg(*args, unsigned long int);
	else if (flag->c[2] == 1)
		res = (uintmax_t)va_arg(*args, unsigned long);
	else if (flag->c[3] == 1)
		res = (uintmax_t)va_arg(*args, unsigned long long);
	else if (flag->c[4] == 1)
		res = va_arg(*args, uintmax_t);
	else if (flag->c[5] == 1)
		res = (uintmax_t)va_arg(*args, size_t);
	else
		res = (uintmax_t)va_arg(*args, unsigned long);
	return (ft_itoa_base(res, 10, flag));
}

int		ft_handle_mu(const char *format, va_list *args, t_flag *flag)
{
	int		len;
	char	*res;

	res = ft_mu(flag, args);
	if (flag->pr != -1)
		res = ft_apply_pre_d(res, flag);
	res = ft_mini_field(res, flag);
	if (flag->z >= 1 && flag->m == 0)
		ft_apply_z(res, flag);
	ft_putstr(res);
	len = ft_strlen(res);
	free(res);
	return (len);
}
