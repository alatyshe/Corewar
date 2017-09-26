/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int					check_syntax(t_header *head, char *read, char *str)
{
	int				x;

	x = 0;
	while (read[x] && read[x] != '#')
	{
		if (!cmp_char_with_str(read[x], str))
		{
			head->x += x;
			return (error_type(head, LEXICAL_ERROR, EMPTY));
		}
		x++;
	}
	return (x);
}

void				check_symbols_after_cmd(t_header *head, char *read)
{
	int				i;

	i = skip_spaces(read);
	if (read[i] && read[i] != '#' && read[i] != ';')
	{
		head->x += i;
		if (read[i] == '%')
			error_type(head, SYNTAX_ERROR, DIRECT);
		else if (read[i] == ',')
			error_type(head, INVALID_PAR, COUNT);
		else if (ft_isdigit(read[i]))
			error_type(head, SYNTAX_ERROR, INDIRECT);
		else
			error_type(head, SYNTAX_ERROR, LBL_INSTR);
	}
}