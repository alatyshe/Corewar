/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:18:56 by alatyshe          #+#    #+#             */
/*   Updated: 2017/01/16 15:28:08 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/ft_printf.h"

void		ft_use_letter(t_pflist *lst, int *count, char letter, va_list ap)
{
	char		*str;
	t_pf_array	use_letter[16];
	int			i;

	i = 0;
	str = "sSpdDioOuUxXcCb";
	ft_create_func_arr(use_letter);
	if (letter == '%')
		ft_percent(lst, count);
	else
	{
		while (str[i] != letter)
			i++;
		use_letter[i](lst, count, ap);
	}
}

int			ft_check_letter(t_pflist *lst, char *str, int i)
{
	char		*s;
	int			j;

	s = "sSpdDioOuUxXcCb%";
	j = 0;
	while (s[j])
	{
		if (str[i] == s[j])
		{
			if (str[i] == 'D' || str[i] == 'O' || str[i] == 'U')
				lst->length = 3;
			return (i);
		}
		j++;
	}
	return (-1);
}

int			ft_lst_use(char *str, int *i, int *count, va_list ap)
{
	t_pflist	*lst;
	int			n;

	lst = ft_create_lst();
	while ((n = ft_check_letter(lst, str, *i)) < 0)
	{
		if (!ft_lst_fill(lst, str, i, ap))
		{
			ft_print_flags(lst, &str[(*i)], count, i);
			free(lst);
			(*i)--;
			return (0);
		}
		(*i)++;
	}
	ft_use_letter(lst, count, str[(*i)], ap);
	free(lst);
	return (0);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			i;
	int			count;
	int			len;

	i = 0;
	count = 0;
	va_start(ap, fmt);
	len = ft_strlen(fmt);
	while (i < len)
	{
		if (fmt[i] == '%')
		{
			i++;
			ft_lst_use((char *)fmt, &i, &count, ap);
		}
		else
		{
			write(1, &fmt[i], 1);
			++count;
		}
		++i;
	}
	va_end(ap);
	return (count);
}
