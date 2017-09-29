/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:36:14 by alatyshe          #+#    #+#             */
/*   Updated: 2017/02/10 17:36:15 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

t_pflist	*ft_create_lst(void)
{
	t_pflist	*lst;

	if (!(lst = (t_pflist*)malloc(sizeof(t_pflist))))
		return (0);
	lst->spc = 0;
	lst->hash = 0;
	lst->plus = 0;
	lst->minus = 0;
	lst->zero = 0;
	lst->width = 0;
	lst->dot = 0;
	lst->prec = 0;
	lst->length = 0;
	lst->decimalize = '0';
	return (lst);
}

void		ft_lst_modify_d(t_pflist *lst, char *str)
{
	int			len;

	len = ft_strlen(str);
	if ((lst->zero == 1 && lst->dot == 1))
		lst->zero = 0;
	if (str[0] == '-')
		len--;
	if (str[0] == '-' || lst->plus == 1 || lst->spc == 1)
	{
		if (lst->spc == 1 && lst->plus == 0)
			lst->decimalize = ' ';
		if (str[0] == '-')
			lst->decimalize = '-';
		else if (lst->plus == 1)
			lst->decimalize = '+';
		lst->plus = 1;
	}
	if (lst->width < len + lst->plus)
		lst->width = len + lst->plus;
	if (lst->prec < len + lst->plus)
		lst->prec = len + lst->plus;
	else if (lst->prec > len)
		lst->prec += lst->plus;
}

void		ft_lst_modify_u(t_pflist *lst, char *str)
{
	int			len;

	len = ft_strlen(str);
	if (lst->plus > 0)
		lst->plus = (lst->dot == 1 && lst->width > 1) ? 1 : 0;
	if ((lst->zero == 1 && lst->dot == 1))
		lst->zero = 0;
	if (lst->width < len + lst->plus)
		lst->width = len + lst->plus;
	if (lst->prec < len + lst->plus)
		lst->prec = len + lst->plus;
	else if (lst->prec > len)
		lst->prec += lst->plus;
}

void		ft_lst_modify_s(t_pflist *lst, char *str)
{
	int			len;

	len = ft_strlen(str);
	if (lst->width < len && lst->dot != 1)
		lst->width = len;
	if (lst->dot == 1 && lst->width <= lst->prec &&
		lst->prec >= len && lst->width <= len)
	{
		lst->width = len;
		lst->prec = len;
	}
	else if (lst->dot == 1 && lst->width <= lst->prec && lst->width >= len)
		lst->prec = len;
	else if (lst->dot == 1 && lst->width <= lst->prec && lst->prec <= len)
	{
		lst->width = lst->prec;
	}
	if (lst->dot == 0)
		lst->prec = len;
}

void		ft_create_func_arr(t_pf_array *use_letter)
{
	use_letter[0] = ft_s;
	use_letter[1] = ft_s_big;
	use_letter[2] = ft_p;
	use_letter[3] = ft_d;
	use_letter[4] = ft_d;
	use_letter[5] = ft_d;
	use_letter[6] = ft_o;
	use_letter[7] = ft_o;
	use_letter[8] = ft_u;
	use_letter[9] = ft_u;
	use_letter[10] = ft_x;
	use_letter[11] = ft_xb;
	use_letter[12] = ft_c;
	use_letter[13] = ft_c;
	use_letter[14] = ft_b;
}
