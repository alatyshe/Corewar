/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:27:57 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/05 19:23:32 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

int		ft_prnstr(char const *s, int length)
{
	int		i;
	char	*b;

	i = 0;
	b = (char *)s;
	if (b)
	{
		if (length == 0)
			while (*b)
			{
				write(1, &(*b++), 1);
				i++;
			}
		else
			while (length > 0 && *b)
			{
				write(1, &(*b++), 1);
				i++;
				length--;
			}
	}
	return (i);
}

int		ft_printstr_big(wchar_t const *s, int length)
{
	int		i;
	wchar_t	*b;

	i = 0;
	b = (wchar_t *)s;
	if (b)
	{
		if (length == 0)
			while (*b)
			{
				i += printing_char((*b++));
			}
		else
			while (length > i && *b)
			{
				i += printing_char((*b++));
				if (length < i + ft_sizeof_wchar((*b)))
					break ;
			}
	}
	return (i);
}

int		ft_sizeof_wchar(wchar_t s)
{
	int		j;

	j = ft_size_bin(s);
	if (j <= 7)
		return (1);
	else if (j <= 11)
		return (2);
	else if (j <= 16)
		return (3);
	else
		return (4);
}

int		ft_char(int i, char b)
{
	int		j;

	j = i;
	while (i > 0)
	{
		write(1, &b, 1);
		i--;
	}
	return (j);
}
