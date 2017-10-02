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

static void			separator_char_error(t_header *head, t_cmd *cmd, char *read)
{
	if (ft_isdigit(read[0]) && check_digits(read) > 0)
		error_arg(cmd, INVALID_PAR, g_tab[cmd->code - 1].count_arg, "indirect");
	else if (read[0] == REGISTER_CHAR && check_digits(read + 2) > 0)
		error_arg(cmd, INVALID_PAR, g_tab[cmd->code - 1].count_arg, "register");
	else if (read[0] == DIRECT_CHAR && check_digits(read + 2) > 0)
		error_arg(cmd, INVALID_PAR, g_tab[cmd->code - 1].count_arg, "direct");
	else if (ft_isdigit(read[0]) && check_digits(read + 2) == 0)
		error_type(head, LEXICAL_ERROR, EMPTY);
	else
		error_type(head, SYNTAX_ERROR, LBL_INSTR);
}

int					check_symbols_after_cmd(t_header *head,
	t_cmd *cmd, char *read)
{
	int				i;

	i = skip_spaces(read);
	if (read[i] && read[i] != COMMENT_CHAR && read[i] != ';')
	{
		head->error = EMPTY;
		if (read[i] == SEPARATOR_CHAR && (++i))
			separator_char_error(head, cmd, read + i);
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
