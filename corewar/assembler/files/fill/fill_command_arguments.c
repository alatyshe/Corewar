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

int					fill_label_distance(t_header *head, char *to_find, t_cmd *position)
{
	t_cmd			*copy;
	int				find;
	int				summ;

	copy = head->commands;
	summ = 0;
	find = 0;
	while (copy->next)
	{
		if (find == 0 && copy->label != NULL
			&& ft_strncmp(copy->label, to_find, find_chars_in_str(to_find, " \n\t\v\r\f,")) == SAME)
			find = -2;
		if (find == 0 && position == copy)
			find = 2;
		if (find == -2)
		{
			if (position == copy)
			{
				find = -1;
				break ;
			}
			summ += copy->cmd_size;
		}
		if (find == 2)
		{
			if (copy->label != NULL
				&& ft_strncmp(copy->label, to_find, find_chars_in_str(to_find, " \n\t\v\r\f,")) == SAME)
			{
				find = 1;
				break ;
			}
			summ += copy->cmd_size;
		}
		copy = copy->next;
	}
	if (find == -1 || find == 1)
		return (summ * find);
	error_type(head, NO_LABEL, DIRECT_LABEL);
	return (0);
}

int					fill_cmd_arg(t_header *head, t_cmd *cmd, char *str, int arg_num)
{
	int				x;

	x = skip_spaces(str);
	if (str[x] == SEPARATOR_CHAR)
		x++;
	if (str[x] == DIRECT_CHAR)
	{
		x++;
		if (str[x] == LABEL_CHAR)
			cmd->arg[arg_num]->num = fill_label_distance(head, str + x + 1, cmd);
		else
			cmd->arg[arg_num]->num = ft_atoi(str + x);
	}
	else if (str[x] == REGISTER_CHAR)
	{
		x++;
		if (str[x] == LABEL_CHAR)
		{
			x--;
			head->error_str = str + x;
			error_type(head, SYNTAX_ERROR, LBL_INSTR);
		}
		else
			cmd->arg[arg_num]->num = ft_atoi(str + x);
		if (cmd->arg[arg_num]->num > 16)
		{
			head->error_str = str + 1;
			x--;
			error_type(head, SYNTAX_ERROR, LBL_INSTR);
		}
	}
	else
		cmd->arg[arg_num]->shrt = ft_atoi(str + x);

	if (head->error != 0)
		return (x);
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
	head->prog_size += cmd->cmd_size;
	while (arg < g_tab[cmd->cmd_in_hex - 1].count_arg)
	{
		pos += fill_cmd_arg(head, cmd, cmd->str + pos, arg);
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
