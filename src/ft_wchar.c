/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 13:03:11 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/03 11:45:25 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_complete(char *str, int n)
{
	char	*ext;
	int		nb;

	nb = 0;
	if (ft_strlen(str) == n)
		return (str);
	n = n - ft_strlen(str);
	ext = malloc(n + 1);
	while (n > 0)
	{
		ext[nb] = '0';
		nb++;
		n--;
	}
	ext[nb] = '\0';
	str = ft_strcatcat(ext, str);
	return (str);
}

int		ft_dec(char *str)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	str = ft_strrev(str);
	while (*str)
	{
		if (*str == '1')
			res += ft_power(2, i);
		str++;
		i++;
	}
	return (res);
}

char	*ft_extract(char *str, int start, int end)
{
	char	*res;
	int		nb;

	nb = 0;
	res = malloc(end - start + 1);
	while (start < end)
	{
		res[nb] = str[start];
		nb++;
		start++;
	}
	res[nb] = '\0';
	return (res);
}
