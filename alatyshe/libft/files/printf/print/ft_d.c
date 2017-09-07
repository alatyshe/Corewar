/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:03:22 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/09 18:03:26 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void	ft_print_one(t_pflist *lst, int *count, char *str)
{
	int		len;

	len = ft_strlen(str) + lst->plus;
	if (lst->prec > len)
		*count += ft_char(lst->prec - len, '0');
	else if (lst->prec < len)
		*count += ft_char(lst->width - len, '0');
	else if (lst->dot == 1 && lst->zero == 1 && lst->prec >= len)
		*count += ft_char(lst->width - lst->prec, '0');
}

void	ft_print_d(t_pflist *lst, int *count, char *str)
{
	if (lst->minus == 0 && lst->width > 0)
	{
		if (lst->zero == 0 && lst->width > lst->prec)
			*count += ft_char(lst->width - lst->prec, ' ');
		if (lst->plus > 0)
			*count += ft_char(1, lst->decimalize);
		ft_print_two(lst, count, str);
		*count += ft_prnstr(str, 0);
	}
	else if (lst->minus == 1 && lst->width > 0)
	{
		if (lst->plus > 0)
			*count += ft_char(1, lst->decimalize);
		ft_print_one(lst, count, str);
		*count += ft_prnstr(str, 0);
		if (lst->width > lst->prec)
			*count += ft_char(lst->width - lst->prec, ' ');
	}
	else
		ft_func_for_zero(lst, count, lst->dot);
}

void	ft_d(t_pflist *lst, int *count, va_list ap)
{
	intmax_t		d;
	char			*res;
	char			*str;

	d = ft_get_signed_from_length(lst, ap);
	res = ft_itoa(d);
	str = res;
	if (res[0] == '-')
		str = res + 1;
	if (lst->dot == 1 && d == 0 && lst->prec == 0)
		*count += ft_char(lst->width - lst->prec, ' ');
	else
	{
		ft_lst_modify_d(lst, res);
		ft_print_d(lst, count, str);
	}
	free(res);
}
