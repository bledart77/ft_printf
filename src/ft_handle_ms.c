/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 15:09:12 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 10:51:55 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_handle_ms(const char *format, va_list *args, t_flag *flag)
{
	int			res;
	int			i;
	wchar_t		*str;

	res = 0;
	i = 0;
	str = va_arg(*args, wchar_t*);
	while (str[i])
		res += ft_disp(str[i++]);
	return (res);
}

int		ft_disp(wchar_t c)
{
	int				len;
	unsigned int	nb;

	nb = (unsigned int)c;
	len = ft_strlen(ft_itoa_base_next_level(nb, "01"));
	if (len <= 7)
		return (ft_7bitchar(ft_itoa_base_next_level(nb, "01")));
	else if (len <= 11)
		return (ft_11bitchar(ft_itoa_base_next_level(nb, "01")));
	else if (len <= 16)
		return (ft_16bitchar(ft_itoa_base_next_level(nb, "01")));
	else
		return (ft_bitchar(ft_itoa_base_next_level(nb, "01")));
}
