/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 10:42:40 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/24 05:07:39 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_apply_do(char *str, t_flag *fag)
{
	char	*res;
	int		i;

	i = 1;
	if (str[0] == '0')
		return (str);
	res = malloc(ft_strlen(str) + 1);
	res[0] = '0';
	while (str[i - 1])
	{
		res[i] = str[i - 1];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_apply_dx(char *str, t_flag *flag)
{
	char	*res;
	int		i;
	int		len;

	len = ft_strlen(str);
	i = 0;
	res = malloc(len + 3);
	res[0] = '0';
	res[1] = flag->h;
	while (i < len)
	{
		res[i + 2] = str[i];
		i++;
	}
	res[i + 2] = '\0';
	return (res);
}
