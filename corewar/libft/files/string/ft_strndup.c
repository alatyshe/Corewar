/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:23:56 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/09 20:47:15 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*res;
	size_t	i;

	i = 0;
	while (s1[i] && i < n)
		i++;
	res = (char*)malloc(sizeof(char) * i + 1);
	if (!res)
		return (0);
	i = 0;
	while (s1[i] && i < n)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
