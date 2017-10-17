/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int					ft_find_char_from_end(char *str, char c)
{
	int				i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (0);
}

void				print_create(t_header *head)
{
	int				i;
	int				j;

	i = ft_find_char_from_end(head->file_name, '/');
	j = ft_find_char_from_end(head->file_name, '.');
	ft_printf("%sWriting output program from %s", GREEN, RESET);
	ft_printf("%s", head->file_name);
	ft_printf("%s to %s", GREEN, RESET);
	if (j > i)
	{
		head->file_name[j] = '\0';
		ft_printf("%s", head->file_name);
		head->file_name[j] = '.';
		ft_printf(".cor\n");
	}
	else
	{
		ft_printf("%s", head->file_name);
		ft_printf(".cor\n");
	}
}
