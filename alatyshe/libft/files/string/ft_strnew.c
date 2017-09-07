/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:11:41 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/09 21:24:16 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*b;

	i = 0;
	b = (char *)malloc(sizeof(char) * (int)size + 1);
	if (b)
	{
		while (size--)
		{
			b[i] = '\0';
			i++;
		}
		b[i] = '\0';
		return (b);
	}
	return (NULL);
}
