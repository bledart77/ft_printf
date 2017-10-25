/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:42:51 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/02 15:59:21 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

long int		ft_power(long int nb, int pow)
{
	long int	res;
	int			i;

	if (pow == 0)
		return (1);
	res = (long int)nb;
	i = 0;
	while (pow > 1)
	{
		res *= (long int)nb;
		pow--;
	}
	return (res);
}
