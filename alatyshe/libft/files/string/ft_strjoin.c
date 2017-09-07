/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 20:20:30 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/04 20:38:30 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*b;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	b = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!b)
		return (NULL);
	while (*str1 || *str2)
	{
		if (*str1)
			b[i] = *str1++;
		else
			b[i] = *str2++;
		i++;
	}
	b[i] = '\0';
	return (b);
}
