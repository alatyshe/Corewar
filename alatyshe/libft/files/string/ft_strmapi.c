/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 18:59:47 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/04 19:03:57 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*b;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	b = (char*)malloc(sizeof(char) * i + 1);
	if (!b)
		return (NULL);
	i = 0;
	while (s[i])
	{
		b[i] = (*f)(i, s[i]);
		i++;
	}
	b[i] = '\0';
	return (b);
}
