/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 23:33:51 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/23 10:40:17 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_apply_p(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (ft_atoi(str) < 0)
		return (str);
	if (str[0] == ' ' && ft_strlen(str) > 1)
	{
		str[0] = '+';
		return (str);
	}
	return (ft_strcatcat("+", str));
}

char	*ft_apply_s(char *str)
{
	char	*res;
	int		i;

	i = 0;
	if (ft_atoi(str) < 0)
		return (str);
	res = malloc(ft_strlen(str) + 2);
	res[0] = ' ';
	while (str[i])
	{
		res[i + 1] = str[i];
		i++;
	}
	res[i + 1] = '\0';
	return (res);
}

void	ft_apply_z(char *str, t_flag *flag)
{
	int		i;
	int		c;

	c = 0;
	i = 0;
	if (flag->pr > 0)
		return ;
	while (str[i])
	{
		if (str[i] == ' ')
			str[i] = '0';
		if (str[i] == flag->h)
		{
			if (c == 0 && flag->d > 0 && (flag->h == 'x'|| flag->h == 'X'))
			{
				c++;
				str[i] = '0';
			}
		}
		i++;
	}
	if (flag->d > 0 && (flag->h == 'x' || flag->h == 'X'))
		str[1] = flag->h;
}

int		ft_dispblank(int n)
{
	int		i;

	i = 0;
	while (i++ < n)
		ft_putchar(' ');
	return (n);
}
