/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 13:41:30 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/25 10:30:10 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_itoa(int nb)
{
	return (ft_itoa_base_next_level(nb, "0123456789"));
}

char	*ft_itoa_hexa(int nb)
{
	return (ft_itoa_base_next_level(nb, "0123456789abcdef"));
}

char	*ft_itoa_base(intmax_t nb, int base, t_flag *flag)
{
	static char		convert[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'
		, '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	intmax_t		i;
	uintmax_t		n;

	int				converted_nb[64];
	char			*res;
	
	if (nb == 0)
		return ("0\0");
	i = 0;
	n = (intmax_t)nb;
	while (n > 0)
	{
		converted_nb[i++] = n % base;
		n /= base;
	}
	res = (char*)malloc(sizeof(char*) * --i);
	res[i + 1] = '\0';
	while (i >= 0)
		res[n++] = convert[converted_nb[i--]];
	if ((nb < 0 && (flag->h == 'd' || flag->h == 'D')) || flag->sign == '-')
		res = ft_strcatcat("-",res);
	return (res);
}

