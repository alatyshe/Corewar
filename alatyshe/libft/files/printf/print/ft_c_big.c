/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:03:11 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/03 20:40:24 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

int		print_wchar_2(unsigned int v)
{
	unsigned char	main_msk;
	unsigned char	octet;
	unsigned char	mask;

	mask = 128;
	main_msk = 192;
	octet = main_msk | ((v >> 6) << 27) >> 27;
	write(1, &octet, 1);
	octet = mask | (v << 26) >> 26;
	write(1, &octet, 1);
	return (2);
}

int		print_wchar_3(unsigned int v)
{
	unsigned char	main_msk;
	unsigned char	octet;
	unsigned char	mask;

	mask = 128;
	main_msk = 224;
	octet = main_msk | ((v >> 12) << 28) >> 28;
	write(1, &octet, 1);
	octet = mask | ((v >> 6) << 26) >> 26;
	write(1, &octet, 1);
	octet = mask | ((v << 26) >> 26);
	write(1, &octet, 1);
	return (3);
}

int		print_wchar_4(unsigned int v)
{
	unsigned char	main_msk;
	unsigned char	octet;
	unsigned char	mask;

	mask = 128;
	main_msk = 240;
	octet = main_msk | ((v >> 18) << 29) >> 29;
	write(1, &octet, 1);
	octet = mask | ((v >> 12) << 26) >> 26;
	write(1, &octet, 1);
	octet = mask | ((v >> 6) << 26) >> 26;
	write(1, &octet, 1);
	octet = mask | ((v << 26) >> 26);
	write(1, &octet, 1);
	return (4);
}

int		printing_char(wchar_t value)
{
	unsigned int	v;
	int				size;
	unsigned char	octet;

	v = value;
	size = ft_size_bin(value);
	if (size <= 7)
	{
		octet = value;
		write(1, &octet, 1);
		return (1);
	}
	else if (size <= 11)
		return (print_wchar_2(v));
	else if (size <= 16)
		return (print_wchar_3(v));
	else
		return (print_wchar_4(v));
}

void	ft_c_big(t_pflist *lst, int *count, va_list ap)
{
	wchar_t value;

	value = (wchar_t)va_arg(ap, wchar_t);
	if (lst->minus == 0 && lst->width > 0 && lst->minus == 0)
	{
		if (lst->zero == 0)
			*count += (ft_char(lst->width - 1, ' ') + 1);
		else
			*count += (ft_char(lst->width - 1, '0') + 1);
		*count += printing_char(value);
	}
	else if (lst->width > 0 && lst->minus == 1)
	{
		*count += printing_char(value);
		*count += (ft_char(lst->width - 1, ' ') + 1);
	}
	else
	{
		*count += printing_char(value);
	}
}
