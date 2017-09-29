/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:47:49 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/03 19:31:57 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *source;
	unsigned char *destination;

	source = (unsigned char*)src;
	destination = (unsigned char*)dst;
	while (n--)
		*destination++ = *source++;
	return (dst);
}
