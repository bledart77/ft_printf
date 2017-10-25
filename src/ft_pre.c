/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 03:16:53 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/23 16:58:31 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_inistr(char *ext, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		ext[i] = '0';
		i++;
	}
	return (ext);
}

char	*ft_apply_pre_d(char *res, t_flag *flag)
{
	char	*ext;
	int		i;
	int		nb;

	i = 0;
	nb = ft_strlen(res) - flag->pr;
	if (nb >= 0)
		return (res);
	nb = -nb;
	ext = malloc(nb + 1);
	ext = ft_inistr(ext, nb);
	if (flag->sign == 1)
	{
		ext = ft_strcatcat("-", ext);
		res[0] = '0';
	}
	return (ft_strcatcat(ext, res));
}

char	*ft_apply_pre_s(char *str, t_flag *flag)
{
	char	*res;
	int		n;

	n = 0;
	if (ft_strlen(str) <= flag->pr)
		return (str);
	res = malloc(flag->pr + 1);
	while (n < flag->pr)
	{
		res[n] = str[n];
		n++;
	}
	res[n] = '\0';
	return (res);
}
