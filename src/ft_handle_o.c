/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 02:58:30 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 09:22:24 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_handle_o(const char *format, va_list *args, t_flag *flag)
{
	int		len;
	char	*res;

	res = ft_x(flag, args);
	res = ft_itoa_base_next_level(ft_atoi((const char*)res), "01234567");
	if (flag->pr != -1)
		res = ft_apply_pre_d(res, flag);
	if (flag->d >= 1)
		res = ft_apply_do(res, flag);
	res = ft_mini_field(res, flag);
	if (flag->z >= 1 && flag->m == 0)
		ft_apply_z(res, flag);
	if (flag->pr == 0 && flag->d == 0)
	{
		free(res);
		return (ft_dispblank(flag->t));
	}
	ft_putstr(res);
	len = ft_strlen(res);
	free(res);
	return (len);
}
