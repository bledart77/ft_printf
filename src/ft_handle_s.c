/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 01:18:38 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/06 15:04:14 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_handle_s(const char *format, va_list *args, t_flag *flag)
{
	int		len;
	char	*res;

	res = va_arg(*args, char*);
	if (res == NULL)
		res = "(null)";
	if (flag->pr != -1)
		res = ft_apply_pre_s(res, flag);
	res = ft_mini_field(res, flag);
	len = ft_strlen(res);
	ft_putstr(res);
	return (len);
}
