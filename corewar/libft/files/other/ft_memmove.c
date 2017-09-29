/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 20:53:18 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/02 21:51:27 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			i;

	i = 0;
	source = (unsigned char*)src;
	destination = (unsigned char*)dst;
	if (source < destination)
		while (len--)
			*(destination + len) = *(source + len);
	else
		while (i++ < len)
			*destination++ = *source++;
	return (dst);
}
