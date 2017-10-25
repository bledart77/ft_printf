/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 23:11:21 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/10 14:39:41 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_pointer(const char *format, va_list *args)
{
	char			*res;
	uintmax_t		nb;

	nb = (uintmax_t)va_arg(*args, void*);
	res = malloc(3);
	res[0] = '0';
	res[1] = 'x';
	res[2] = '\0';
	res = ft_strcat(res, ft_itoa_b_n_l_u(nb, "0123456789abcdef", 65));
	return (res);
}

int		ft_handle_p(const char *format, va_list *args, t_flag *flag)
{
	char	*res;
	int		len;

	res = ft_pointer(format, args);
	res = ft_mini_field(res, flag);
	len = ft_strlen(res);
	if (len >= flag->t)
	{
		ft_putstr(res);
		free(res);
		return (len);
	}
	else
	{
		ft_putstr(res);
		while (len++ < flag->t)
			ft_putchar(' ');
	}
	free(res);
	return (flag->t);
}
