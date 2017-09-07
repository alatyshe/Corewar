/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:49:31 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/01 21:17:57 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		while (little[j] == big[i + j] && little[j] != '\0'
				&& j + i < len)
			j++;
		if (little[j] == '\0')
			return ((char*)big + i);
		i++;
	}
	if (big[0] == '\0' && little[0] == '\0')
		return ((char*)big);
	return (NULL);
}
