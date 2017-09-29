/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 18:03:11 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/09 18:03:12 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void		ft_for_s_big_min(t_pflist *lst, wchar_t *str, int *count)
{
	int			len;
	int			j;

	j = *count;
	len = ft_strlen_big(str);
	if (lst->zero == 0 && lst->prec > len)
		*count += (ft_char(lst->prec - len, ' '));
	if (*str && ((lst->dot == 1 && lst->prec > 0) || lst->dot == 0))
		*count += ft_printstr_big(str, lst->prec);
	if (lst->zero == 0 && lst->width > lst->prec)
		*count += (ft_char(lst->width - (*(count) - j), ' '));
	else if (lst->zero == 1 && lst->prec <= len)
		*count += (ft_char(lst->width - lst->prec, '0'));
	else if (lst->zero == 1 && lst->prec >= len)
		*count += (ft_char(lst->width - len, '0'));
}

void		ft_for_s_big_plus(t_pflist *lst, wchar_t *str, int *count)
{
	int			len;
	int			j;

	j = *count;
	len = ft_strlen_big(str);
	if (lst->zero == 0)
		*count += (ft_char(lst->width - lst->prec, ' '));
	else if (lst->zero == 1 && lst->prec <= len)
		*count += (ft_char(lst->width - lst->prec, '0'));
	else if (lst->zero == 1 && lst->prec >= len)
		*count += (ft_char(lst->width - len, '0'));
	if (lst->zero == 0 && lst->prec > len)
		*count += (ft_char(lst->prec - len, ' '));
	if (*str && ((lst->dot == 1 && lst->prec > 0) || lst->dot == 0))
		*count += ft_printstr_big(str, lst->prec);
	if (*count - j < lst->prec && lst->dot == 1 && len < lst->prec)
		*count += (ft_char(lst->prec - (*count - j), ' '));
}

void		ft_for_s_big(t_pflist *lst, wchar_t *str, int *count)
{
	int			len;

	len = ft_strlen_big(str);
	if (lst->minus == 0 && lst->width > 0)
		ft_for_s_big_plus(lst, str, count);
	else if (lst->minus == 1 && lst->width > 0)
		ft_for_s_big_min(lst, str, count);
	else
	{
		if (lst->dot == 0)
			*count += ft_printstr_big(str, lst->prec);
		else if (lst->dot > 0 && lst->prec > 0)
			*count += ft_printstr_big(str, lst->prec);
	}
}

void		ft_s_big(t_pflist *lst, int *count, va_list ap)
{
	wchar_t		*str;

	str = (wchar_t *)va_arg(ap, wchar_t *);
	if (str == NULL)
	{
		str = L"(null)";
	}
	ft_lst_modify_sb(lst, str);
	ft_for_s_big(lst, str, count);
}
