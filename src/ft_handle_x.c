/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 03:48:25 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 09:17:03 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_x(t_flag *flag, va_list *args)
{
	uintmax_t		res;

	if (flag->c[0] == 1)
		res = (uintmax_t)(char)va_arg(*args, int);
	else if (flag->c[1] == 1)
		res = (uintmax_t)(short)va_arg(*args, int);
	else if (flag->c[2] == 1)
		res = (uintmax_t)va_arg(*args, long);
	else if (flag->c[3] == 1)
		res = (uintmax_t)va_arg(*args, long long);
	else if (flag->c[4] == 1)
		res = va_arg(*args, uintmax_t);
	else if (flag->c[5] == 1)
		res = (uintmax_t)va_arg(*args, size_t);
	else
		res = (uintmax_t)va_arg(*args, int);
	return (ft_itoa_base(res, 10, flag));
}

char	*ft_handle_x_ext(char *res, t_flag *flag)
{
	int		n;
	char	*hexa;
	char	*hexam;

	hexa = "0123456789abcdef";
	hexam = "0123456789ABCDEF";
	n = 33;
	if (flag->c[4] == 1)
		n = 65;
	if (flag->h == 'x')
		return (ft_itoa_b_n_l_u(ft_atoi_l_l((const char*)res), hexa, n));
	if (flag->h == 'X')
		return (ft_itoa_b_n_l_u(ft_atoi_l_l((const char*)res), hexam, n));
	return (NULL);
}

int		ft_handle_x(const char *format, va_list *args, t_flag *flag)
{
	int		len;
	char	*res;

	res = ft_x(flag, args);
	res = ft_handle_x_ext(res, flag);
	if (flag->pr != -1)
		res = ft_apply_pre_d(res, flag);
	if (flag->d >= 1 && ft_atoi(res) != 0 && res != NULL)
		res = ft_apply_dx(res, flag);
	res = ft_mini_field(res, flag);
	if (flag->z >= 1 && flag->m == 0 && res != NULL)
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
