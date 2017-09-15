/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"				

int					check_syntax(t_header *head, char *read)
{
	int				x;

	x = 0;
	while (read[x])
	{
		if (!cmp_char_with_str(read[x], AVAILABLE_CHARS))
			return (error_message_type(LEXICAL_ERROR, head, x, EMPTY));
		x++;
	}
	return (skip_spaces(read));
}

int					fill_instruction(t_header *head, char *read, int fd)
{
	return (1);
}

int					check_label_and_func(t_header *head, char *read, int fd)
{
	int				x;
	t_function		*func;
	t_function		*new_func;
	int 			i;

	
	x = check_syntax(head, read);
	if (head->error == 0 && read[x])
	{
		func = get_last_function(head);
		if (read[x] == '#')
			return (0);
		x = check_label_presence(head, func, read + x, fd);
		if (head->error > 0)
			return (x);
		x = skip_spaces(read + x) + x;
		if (fill_function(head, func, read + x, fd))
		{
			new_func = create_t_function();
			func->next = new_func;
			new_func->prev = func;
		}
		else
			return (error_message_type(SYNTAX_ERROR, head, x + 1, LBL_INSTR));
	}
	return (x + 1);
}
