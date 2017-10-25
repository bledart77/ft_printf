/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 02:29:36 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/23 17:15:29 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_swap_sign(char *str)
{
	int		i;
	char	c;

	c = 'z';
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
		{
			c = str[i];
			str[i] = '0';
		}
		i++;
	}
	if (c != 'z')
		str[0] = c;
	return (str);
}

char	*ft_d(t_flag *flag, va_list *args)
{
	intmax_t	res;
	uintmax_t	resmax;

	if (flag->c[0] == 1)
		res = (intmax_t)(char)va_arg(*args, int);
	else if (flag->c[1] == 1)
		res = (intmax_t)(short)va_arg(*args, int);
	else if (flag->c[2] == 1)
		res = (intmax_t)va_arg(*args, long);
	else if (flag->c[3] == 1)
	{
		res = (intmax_t)va_arg(*args, long long);
		return (ft_itoa_base(res, 10, flag));
	}
	else if (flag->c[4] == 1)
	{
		res = va_arg(*args, intmax_t);
		return (ft_itoa_base(res, 10, flag));
	}
	else if (flag->c[5] == 1)
		res = (intmax_t)va_arg(*args, size_t);
	else
		res = va_arg(*args, int);
	if (res < 0)
		flag->sign = 1;
	return (ft_int_to_char_long(res));
}

int		ft_handle_d(const char *format, va_list *args, t_flag *flag)
{
	char		*res;
	int			len;

	res = ft_d(flag, args);
	if (flag->pr != -1)
		res = ft_apply_pre_d(res, flag);
	if (flag->s >= 1 && flag->p == 0)
		res = ft_apply_s(res);
	if (flag->p >= 1)
		res = ft_apply_p(res);
	res = ft_mini_field(res, flag);
	if (flag->z >= 1 && flag->m == 0)
	{
		ft_apply_z(res, flag);
		res = ft_swap_sign(res);
	}
	if (flag->pr == 0 && ft_atoi(res) == 0)
	{
		free(res);
		return (ft_dispblank(flag->t));
	}
	ft_putstr(res);
	len = ft_strlen(res);
	free(res);
	return (len);
}
