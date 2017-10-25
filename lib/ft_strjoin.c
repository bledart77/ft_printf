/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:30:01 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/08/16 00:05:34 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	if (!(res = (char*)malloc(l1 + 1)))
		return (NULL);
	ft_strcpy(res, (char*)s1);
	ft_strcat(res, (char*)s2);
	return (res);
}
