/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 11:46:58 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/05 12:21:17 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

int		ft_handle_percent(t_flag *flag)
{
	char	*str;
	int		res;

	str = malloc(2);
	str[0] = '%';
	str[1] = '\0';
	str = ft_mini_field(str, flag);
	ft_putstr(str);
	res = ft_strlen(str);
	free(str);
	return (res);
}
