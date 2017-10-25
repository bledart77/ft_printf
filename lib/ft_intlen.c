/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:37:41 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/09/28 16:02:10 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_intlen(int nb)
{
	int		res;

	res = 1;
	while (nb >= 10)
	{
		res++;
		nb /= 10;
	}
	return (res);
}

int		ft_long_intlen(long int nb)
{
	int		res;

	res = 1;
	while (nb >= 10)
	{
		res++;
		nb /= 10;
	}
	return (res);
}
