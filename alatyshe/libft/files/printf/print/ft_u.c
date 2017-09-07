/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:04:14 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/09 18:04:15 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void	ft_print_two(t_pflist *lst, int *count, char *str)
{
	int		len;

	len = ft_strlen(str) + lst->plus;
	if (lst->prec > len)
		*count += ft_char(lst->prec - len, '0');
	else if (lst->prec < len)
		*count += ft_char(lst->width - len, '0');
	else if (lst->zero == 1 && lst->prec >= len)
		*count += ft_char(lst->width - lst->prec, '0');
}

void	ft_print_u(t_pflist *lst, int *count, char *str)
{
	if (lst->minus == 0 && lst->width > 0)
	{
		if (lst->zero == 0 && lst->width > lst->prec)
			*count += ft_char(lst->width - lst->prec, ' ');
		ft_print_two(lst, count, str);
		*count += ft_prnstr(str, 0);
	}
	else if (lst->minus == 1 && lst->width > 0)
	{
		ft_print_one(lst, count, str);
		*count += ft_prnstr(str, 0);
		if (lst->width > lst->prec)
			*count += ft_char(lst->width - lst->prec, ' ');
	}
	else
		ft_func_for_zero(lst, count, lst->dot);
}

void	ft_u(t_pflist *lst, int *count, va_list ap)
{
	size_t				d;
	char				*str;

	d = ft_get_unsigned_from_length(lst, ap);
	str = ft_itoa_base_p(d, 10);
	if (lst->dot == 1 && d == 0 && lst->prec == 0)
		*count += ft_char(lst->width - lst->prec, ' ');
	else
	{
		ft_lst_modify_u(lst, str);
		ft_print_u(lst, count, str);
	}
	free(str);
}
