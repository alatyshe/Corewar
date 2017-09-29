/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:03:11 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/09 18:03:12 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void	ft_print_b(t_pflist *lst, int *count, char *str)
{
	int		len;

	len = ft_strlen(str);
	if (str[0] != '0' && lst->minus == 1 && lst->width > 0)
	{
		*count += ft_char(lst->prec - len, '0');
		*count += (lst->zero == 0) ? ft_prnstr(str, 0)
			: ft_char(lst->width - len, '0');
		*count += (lst->zero == 0) ? ft_char(lst->width - lst->prec, ' ')
			: ft_prnstr(str, 0);
	}
	else if (str[0] != '0' && lst->minus == 0 && lst->width > 0)
	{
		*count += (lst->zero == 0) ? ft_char(lst->width - lst->prec, ' ') : 0;
		*count += ft_char(lst->prec - len, '0');
		*count += (lst->zero > 0) ? ft_char(lst->width - len, '0') : 0;
		*count += ft_prnstr(str, 0);
	}
	else
		ft_func_for_zero(lst, count, lst->dot);
}

void	ft_b(t_pflist *lst, int *count, va_list ap)
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
		str = ft_itoa_base_p(d, 2);
	ft_lst_modify_b(lst, str);
	ft_print_o(lst, count, str);
	free(str);
}
