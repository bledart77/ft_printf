/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_mc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 01:46:49 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 10:51:35 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_handle_mc(const char *format, va_list *args, t_flag *flag)
{
	unsigned int	nb;
	int				bytelen;

	nb = va_arg(*args, unsigned int);
	bytelen = ft_strlen(ft_itoa_base_next_level(nb, "01"));
	if (bytelen <= 7)
		return (ft_7bitchar(ft_itoa_base_next_level(nb, "01")));
	else if (bytelen <= 11)
		return (ft_11bitchar(ft_itoa_base_next_level(nb, "01")));
	else if (bytelen <= 16)
		return (ft_16bitchar(ft_itoa_base_next_level(nb, "01")));
	else
		return (ft_bitchar(ft_itoa_base_next_level(nb, "01")));
}

int		ft_7bitchar(char *str)
{
	int		tab[1];

	tab[0] = ft_dec(str);
	write(1, &(tab[0]), 1);
	return (1);
}

int		ft_11bitchar(char *str)
{
	int		tab[2];

	str = ft_complete(str, 11);
	tab[0] = ft_dec(ft_strcatcat("110", ft_extract(str, 0, 5)));
	tab[1] = ft_dec(ft_strcatcat("10", ft_extract(str, 5, 11)));
	write(1, &(tab[0]), 1);
	write(1, &(tab[1]), 1);
	free(str);
	return (2);
}

int		ft_16bitchar(char *str)
{
	int		tab[3];

	str = ft_complete(str, 16);
	tab[0] = ft_dec(ft_strcatcat("1110", ft_extract(str, 0, 4)));
	tab[1] = ft_dec(ft_strcatcat("10", ft_extract(str, 4, 10)));
	tab[2] = ft_dec(ft_strcatcat("10", ft_extract(str, 10, 16)));
	write(1, &(tab[0]), 1);
	write(1, &(tab[1]), 1);
	write(1, &(tab[2]), 1);
	free(str);
	return (3);
}

int	ft_bitchar(char *str)
{
	int		tab[4];

	str = ft_complete(str, 21);
	tab[0] = ft_dec(ft_strcatcat("11110", ft_extract(str, 0, 3)));
	tab[1] = ft_dec(ft_strcatcat("10", ft_extract(str, 3, 9)));
	tab[2] = ft_dec(ft_strcatcat("10", ft_extract(str, 9, 15)));
	tab[3] = ft_dec(ft_strcatcat("10", ft_extract(str, 15, 21)));
	write(1, &(tab[0]), 1);
	write(1, &(tab[1]), 1);
	write(1, &(tab[2]), 1);
	write(1, &(tab[3]), 1);
	free(str);
	return (4);
}
