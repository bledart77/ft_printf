/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 04:13:00 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/23 10:22:40 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_field_null(t_flag *flag)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(flag->t + 1);
	while (i < flag->t)
	{
		res[i] = ' ';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_mini_field(char *res, t_flag *flag)
{
	int		nb;
	char	*ext;
	int		n;

	if (res == NULL)
		return (ft_field_null(flag));
	nb = flag->t - ft_strlen(res);
	if (nb < 0 || flag->t == 0)
		return (res);
	ext = malloc(nb + 1);
	n = 0;
	while (n < nb)
	{
		ext[n] = ' ';
		n++;
	}
	ext[n] = '\0';
	if (flag->m == 0)
		res = ft_strcatcat(ext, res);
	else
		res = ft_strcatcat(res, ext);
	free(ext);
	return (res);
}
