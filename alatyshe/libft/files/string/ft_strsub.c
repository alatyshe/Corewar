/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:14:02 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 18:17:06 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (len > 0)
	{
		str[i] = s[i + start];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
