/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 09:58:12 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/10 14:08:23 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_int_to_char(int nb)
{
	char	*res;
	int		i;
	int		tmp;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i = 1;
		tmp = i;
	}
	res = malloc(i + 1 + ft_intlen(nb));
	if (i == 1)
		res[0] = '-';
	i = i + ft_intlen(nb) - 1;
	res[i + 1] = '\0';
	while (nb >= 10)
	{
		res[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	res[i] = nb + '0';
	return (res);
}

char	*ft_int_to_char_unsigned(long int nb, int nb_byte)
{
	char		*res;
	long int	i;

	i = 0;
	if (nb < 0)
		nb = ft_power(2, nb_byte - 1) + nb;
	res = malloc(i + 1 + ft_long_intlen(nb));
	i = i + ft_long_intlen(nb);
	res[i] = '\0';
	while (nb >= 10)
	{
		res[i - 1] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	res[0] = nb + '0';
	return (res);
}

char	*ft_int_to_char_long(long int nb)
{
	char		*res;
	long int	i;
	long int	tmp;

	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i = 1;
		tmp = i;
	}
	res = malloc(i + 1 + ft_long_intlen(nb));
	if (i == 1)
		res[0] = '-';
	i = i + ft_long_intlen(nb) - 1;
	res[i + 1] = '\0';
	while (nb >= 10)
	{
		res[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	res[i] = nb + '0';
	return (res);
}
