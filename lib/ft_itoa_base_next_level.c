/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_next_level.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 08:47:22 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/10 14:58:25 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

static int		ft_tailleres(int nb, int len)
{
	int		res;

	res = 0;
	while (nb >= len)
	{
		res++;
		nb /= len;
	}
	return (res);
}

char			*ft_itoa_base_next_level(int nb, char *base)
{
	int		len;
	char	*res;
	int		tmp;
	int		i;

	i = 0;
	tmp = nb;
	len = ft_strlen(base);
	res = (char*)malloc(ft_tailleres(nb, len) + 1);
	while (tmp >= len)
	{
		res[i] = base[tmp % len];
		tmp /= len;
		i++;
	}
	res[i] = base[tmp];
	res = ft_strrev(res);
	res[i + 1] = '\0';
	return (res);
}

char			*ft_itoa_b_n_l_u(long long int nb, char *base, int nb_byte)
{
	unsigned long long int		len;
	char						*res;
	unsigned long long int		tmp;
	int							i;

	if (nb < 0)
		nb = ft_power(2, nb_byte - 1) + nb;
	i = 0;
	tmp = nb;
	len = ft_strlen(base);
	res = (char*)malloc(ft_tailleres(nb, len) + 1);
	while (tmp >= len)
	{
		res[i] = base[tmp % len];
		tmp /= len;
		i++;
	}
	res[i] = base[tmp];
	res = ft_strrev(res);
	res[i + 1] = '\0';
	return (res);
}

char			*ft_itoa_b_n_l_intmax(intmax_t nb, char *base)
{
	unsigned long long int		len;
	char						*res;
	long long int				tmp;
	int							i;

	i = 0;
	tmp = nb;
	len = ft_strlen(base);
	res = (char*)malloc(ft_tailleres(nb, len) + 1);
	while (tmp >= len)
	{
		res[i] = base[tmp % len];
		tmp /= len;
		i++;
	}
	res[i] = base[tmp];
	res = ft_strrev(res);
	res[i + 1] = '\0';

	if (nb < 0)
		res = ft_strcatcat("-", res);
	return (res);
}

char			*ft_itoa_base_next_level_long(long int nb, char *base)
{
	int				len;
	char			*res;
	long int		tmp;
	long int		i;

	i = 0;
	tmp = nb;
	len = ft_strlen(base);
	res = (char*)malloc(ft_tailleres(nb, len) + 1);
	while (tmp >= len)
	{
		res[i] = base[tmp % len];
		tmp /= len;
		i++;
	}
	res[i] = base[tmp];
	res = ft_strrev(res);
	res[i + 1] = '\0';
	return (res);
}
