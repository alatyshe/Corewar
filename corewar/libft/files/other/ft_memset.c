/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:44:51 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/02 15:35:27 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *a;

	a = (unsigned char*)b;
	while ((int)len != 0)
	{
		*a++ = (unsigned char)c;
		len--;
	}
	return (b);
}
