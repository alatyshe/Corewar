/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_octals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 20:05:08 by alatyshe          #+#    #+#             */
/*   Updated: 2017/01/28 20:05:09 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

size_t		ft_get_unsigned_from_length(t_pflist *lst, va_list ap)
{
	size_t		a;

	if (lst->length == 1)
		a = (unsigned char)va_arg(ap, long);
	else if (lst->length == 2)
		a = (unsigned short)va_arg(ap, long);
	else if (lst->length == 3)
		a = va_arg(ap, unsigned long);
	else if (lst->length == 4)
		a = va_arg(ap, unsigned long long);
	else if (lst->length == 5)
		a = va_arg(ap, uintmax_t);
	else if (lst->length == 6)
		a = va_arg(ap, size_t);
	else
		a = va_arg(ap, unsigned);
	return (a);
}

intmax_t	ft_get_signed_from_length(t_pflist *lst, va_list ap)
{
	intmax_t	a;

	a = va_arg(ap, intmax_t);
	if (lst->length == 1)
		a = (char)a;
	else if (lst->length == 2)
		a = (short)a;
	else if (lst->length == 3)
		a = (long)a;
	else if (lst->length == 4)
		a = (long long)a;
	else if (lst->length == 5)
		a = (intmax_t)a;
	else if (lst->length == 6)
		a = (size_t)a;
	else
		a = (int)a;
	return (a);
}

void		ft_fill_itoa(size_t value, size_t base, char *str, int *i)
{
	char			*sstm;

	sstm = "0123456789abcdef";
	if (value >= base)
		ft_fill_itoa(value / base, base, str, i);
	str[(*i)++] = sstm[(value % base)];
}

char		*ft_itoa_base_p(size_t join, int sstm)
{
	char			*res;
	int				i;

	i = 0;
	res = (char *)malloc(sizeof(char) * 64);
	ft_fill_itoa(join, (size_t)sstm, res, &i);
	res[i] = '\0';
	return (res);
}
