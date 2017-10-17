/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_o.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:03:32 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/09 18:03:33 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void	ft_func_for_zero(t_pflist *lst, int *count, int flag)
{
	lst->prec = (flag > 0) ? 1 : 0;
	if (lst->minus == 1)
	{
		if (lst->decimalize != '0')
			*count += ft_char(1, lst->decimalize);
		*count += ft_char(lst->prec, '0');
		*count += (lst->width > lst->prec)
			? ft_char(lst->width - lst->prec, ' ') : 0;
	}
	else if (lst->minus == 0)
	{
		if (lst->decimalize != '0')
			*count += ft_char(1, lst->decimalize);
		*count += (lst->width > lst->prec && lst->zero == 0)
			? ft_char(lst->width - lst->prec, 'f') : 0;
		*count += (lst->zero == 1) ?
			ft_char(lst->width - lst->prec, '0') : 0;
		*count += ft_char(lst->prec, '0');
	}
}

void	ft_print_o(t_pflist *lst, int *count, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (str[0] != '0' && lst->minus == 0 && lst->width > 0)
	{
		if ((lst->zero == 0 || lst->prec > len) && lst->width > lst->prec)
			*count += ft_char(lst->width - lst->prec, ' ');
		if (lst->hash > 0)
			*count += ft_char(1, '0');
		ft_print_two(lst, count, str);
		*count += ft_prnstr(str, 0);
	}
	else if (str[0] != '0' && lst->minus == 1 && lst->width > 0)
	{
		if (lst->zero == 1 && lst->width > lst->prec)
			*count += ft_char(lst->width - lst->prec, '0');
		if (lst->hash > 0)
			*count += ft_char(1, '0');
		ft_print_one(lst, count, str);
		*count += ft_prnstr(str, 0);
		if (lst->zero == 0 && lst->width > lst->prec)
			*count += ft_char(lst->width - lst->prec, ' ');
	}
	else
		ft_func_for_zero(lst, count, (lst->hash == 1 || lst->dot == 0) ? 1 : 0);
}

void	ft_o(t_pflist *lst, int *count, va_list ap)
{
	size_t			d;
	char			*str;

	d = ft_get_unsigned_from_length(lst, ap);
	if (d == 0)
	{
		str = ft_strnew(2);
		str[0] = '0';
	}
	else
		str = ft_itoa_base_p(d, 8);
	ft_lst_modify_o(lst, str);
	ft_print_o(lst, count, str);
	free(str);
}
