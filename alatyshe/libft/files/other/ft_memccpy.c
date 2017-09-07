/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:40:35 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/03 19:34:04 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			i;
	unsigned char	b;

	b = c;
	i = 0;
	source = (unsigned char*)src;
	destination = (unsigned char*)dst;
	while (n--)
	{
		if (source[i] == b)
		{
			destination[i] = source[i];
			return (destination + i + 1);
		}
		destination[i] = source[i];
		i++;
	}
	return (NULL);
}
