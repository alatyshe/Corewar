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
	while (read[x] && read[x] != COMMENT_CHAR)
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

static int			check_digits(char *read)
{
	int				x;

	x = 0;
	if (read[x] == '-')
		x++;
	while (read[x] && read[x] != SEPARATOR_CHAR
		&& !ft_isblank(read[x]) && read[x] != ';')
	{
		if (!ft_isdigit(read[x]))
			return (-1);
		x++;
	}
	return (x);
}

int					check_symbols_after_cmd(t_header *head, t_cmd *cmd, char *read)
{
	int				i;

	i = skip_spaces(read);
	if (read[i] && read[i] != COMMENT_CHAR && read[i] != ';')
	{
		head->error = EMPTY;
		if (read[i] == SEPARATOR_CHAR)
		{
			i++;
			if (ft_isdigit(read[i]) && check_digits(read + i) > 0)
				error_arguments(cmd, INVALID_PAR, g_tab[cmd->cmd_in_hex - 1].count_arg, "indirect");
			else if (read[i] == REGISTER_CHAR && check_digits(read + 2) > 0)
				error_arguments(cmd, INVALID_PAR, g_tab[cmd->cmd_in_hex - 1].count_arg, "register");
			else if (read[i] == DIRECT_CHAR && check_digits(read + 2) > 0)
				error_arguments(cmd, INVALID_PAR, g_tab[cmd->cmd_in_hex - 1].count_arg, "direct");
			else if (ft_isdigit(read[i]) && check_digits(read + 2) == 0)
				error_type(head, LEXICAL_ERROR, EMPTY);
			else
				error_type(head, SYNTAX_ERROR, LBL_INSTR);
		}
		else if (read[i] == DIRECT_CHAR && check_digits(read + 1) > 0)
			error_type(head, SYNTAX_ERROR, DIRECT);
		else if (read[i] == REGISTER_CHAR && check_digits(read + 1) > 0)
			error_type(head, SYNTAX_ERROR, REGISTER);
		else if (ft_isdigit(read[i]) && check_digits(read) > 0)
			error_type(head, SYNTAX_ERROR, INDIRECT);
		else if (ft_isdigit(read[0]) && check_digits(read + 1) == 0)
			error_type(head, LEXICAL_ERROR, EMPTY);
		else
			error_type(head, SYNTAX_ERROR, LBL_INSTR);
	}
	return (i);
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
