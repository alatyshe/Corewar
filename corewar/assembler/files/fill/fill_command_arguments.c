/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

/*
**		check on first symbol in str, and fill argument (only for T_DIR T_IND)
*/

static void			get_value_dir_ind(t_header *head, t_cmd *cmd,
	char *str, int arg_num)
{
	if (str[0] == LABEL_CHAR)
		cmd->arg[arg_num]->num = get_label_distance(head, str + 1, cmd);
	else
		cmd->arg[arg_num]->num = ft_atoi(str);
}

/*
**		same get_value_dir_ind but for T_REG
*/

static int			get_value_reg(t_header *head, t_cmd *cmd,
	char *str, int arg_num)
{
	cmd->arg[arg_num]->num = ft_atoi(str);
	if (cmd->arg[arg_num]->num > 16 || cmd->arg[arg_num]->num < 1
		|| str[0] == LABEL_CHAR)
	{
		head->error_str = str - 1;
		error_type(head, SYNTAX_ERROR, LBL_INSTR);
		return (-1);
	}
	return (0);
}

/*
**		detect argument types
*/

static int			detect_arg_type(t_header *head, t_cmd *cmd,
	char *str, int arg_num)
{
	int				x;

	x = skip_spaces(str);
	x += (str[x] == SEPARATOR_CHAR) ? 1 : 0;
	x += skip_spaces(str + x);
	if (str[x] == DIRECT_CHAR)
	{
		x += 1;
		get_value_dir_ind(head, cmd, str + x, arg_num);
	}
	else if (str[x] == REGISTER_CHAR)
	{
		x += 1;
		x += get_value_reg(head, cmd, str + x, arg_num);
	}
	else
		get_value_dir_ind(head, cmd, str + x, arg_num);
	if (head->error == 0)
		x += check_number(head, str + x);
	return (x);
}

static int			fill_arguments(t_header *head, t_cmd *cmd)
{
	int				arg;
	int				pos;

	pos = 0;
	arg = 0;
	head->x = 0;
	head->prog_size += cmd->size;
	while (arg < g_tab[cmd->code - 1].count_arg)
	{
		pos += detect_arg_type(head, cmd, cmd->str + pos, arg);
		if (head->error > 0)
		{
			head->line = cmd->line;
			head->x = cmd->x + pos;
			error_line_char(head, head->error_str);
			return (0);
		}
		arg++;
	}
	return (1);
}

void				fill_command_arguments(t_header *head)
{
	t_cmd			*copy_cmd;
	int				count;

	copy_cmd = head->commands;
	if (!copy_cmd)
	{
		error_type(head, SYNTAX_ERROR, END);
		error_line_char(head, head->error_str);
		return ;
	}
	while (copy_cmd->next)
	{
		if (copy_cmd->str != NULL)
			if (!fill_arguments(head, copy_cmd))
				return ;
		copy_cmd = copy_cmd->next;
	}
}
