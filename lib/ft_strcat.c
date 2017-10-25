/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcolas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 21:35:26 by mcolas-d          #+#    #+#             */
/*   Updated: 2017/10/10 15:32:46 by mcolas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printf.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (src == NULL)
		return (dest);
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcatc(char *dest, const char c)
{
	int		i;

	i = 0;
	while (dest[i])
		i++;
	dest[i] = c;
	i++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcatcat(char *s1, char *s2)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = (ft_strlen(s1) + ft_strlen(s2));
	res = malloc(len);
	while (*s1)
		res[i++] = *s1++;
	while (*s2)
		res[i++] = *s2++;
	res[i++] = '\0';
	return (res);
}
