/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 19:34:30 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/06 14:34:09 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_atoi(const char *str)
{
	int i;
	int res;
	int neg;

	if (str == NULL)
		return (0);
	neg = 1;
	res = 0;
	i = 0;
	while (str[i] == '\r' || str[i] == '\f' || str[i] == ' ' ||
		str[i] == '\v' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] <= '9' && str[i] >= '0') && str[i])
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}

long long int		ft_atoi_l_l(const char *str)
{
	int				i;
	long long int	res;
	int				neg;

	neg = 1;
	res = 0;
	i = 0;
	while (str[i] == '\r' || str[i] == '\f' || str[i] == ' ' ||
		str[i] == '\v' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] <= '9' && str[i] >= '0') && str[i])
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res * neg);
}
