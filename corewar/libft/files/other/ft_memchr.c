/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:52:52 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/03 19:34:47 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	to_find;
	size_t			i;

	i = 0;
	src = (unsigned char*)s;
	to_find = (unsigned char)c;
	while (n--)
	{
		if (src[i] == to_find)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
