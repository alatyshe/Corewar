/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

static int			check_empty(t_header *head, char *read, int x)
{
	if (x == 0)
	{
		error_type(head, SYNTAX_ERROR, LBL_INSTR);
		return (-1);
	}
	else if (x == 1 && read[0] == '-')
	{
		error_type(head, LEXICAL_ERROR, EMPTY);
		return (0);
	}
	x += skip_spaces(read + x);
	return (x);
}

int					check_number(t_header *head, char *read)
{
	int				x;
	int				indicator;

	x = 0;
	indicator = 0;
	if (read[x] == LABEL_CHAR)
		indicator = 1;
	if (ft_isblank(read[x]))
	{
		error_type(head, LEXICAL_ERROR, EMPTY);
		return (x);
	}
	if (read[x] == '-')
		x++;
	while (read[x] && read[x] != SEPARATOR_CHAR
		&& !ft_isblank(read[x]) && read[x] != ';')
	{
		if (!ft_isdigit(read[x]) && indicator == 0)
		{
			error_type(head, SYNTAX_ERROR, LBL_INSTR);
			return (x);
		}
		x++;
	}
	return (check_empty(head, read, x));
}
