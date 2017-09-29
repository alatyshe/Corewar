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
	printf("%sfill_label_distance%s\n", GREEN,RESET);
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
	// лейбл не найден
	printf("\n%sfill_label_distance%s\n", RED, RESET);
	error_type(head, NO_LABEL, DIRECT_LABEL);
	return (0);
}

int					fill_cmd_arg(t_header *head, t_cmd *cmd, char *str, int arg_num)
{
	int				x;

	x = skip_spaces(str);
	printf("%sfill_cmd_arg%s\n", GREEN,RESET);
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
			cmd->arg[arg_num]->num = fill_label_distance(head, str + x + 1, cmd);
		else
			cmd->arg[arg_num]->num = ft_atoi(str + x);
	}
	else
		cmd->arg[arg_num]->shrt = ft_atoi(str + x);

	if (head->error != 0)
		return (x);
	x += check_number(head, str + x);
	return (x);
}

void				fill_arguments(t_header *head, t_cmd *cmd)
{
	t_cmd			*copy_cmd;
	int				arg;
	int				x;

	copy_cmd = cmd;
	// printf("%sfill_arguments%s\n", GREEN,RESET);
	while (copy_cmd->next)
	{
		if (copy_cmd->str != NULL)
		{
			arg = 0;
			x = skip_spaces(copy_cmd->str);
			head->prog_size += copy_cmd->cmd_size;
			while (arg < g_tab[copy_cmd->cmd_in_hex - 1].count_arg)
			{
				x += fill_cmd_arg(head, copy_cmd, copy_cmd->str + x, arg);
				if (head->error > 0)
				{
					head->line = copy_cmd->line;
					head->x = copy_cmd->x + x;
					// printf("\n%s fill_arguments%s\n", RED, RESET);
					// printf("%s\n", copy_cmd->str);
					error_line_char(head, copy_cmd->str);
					return ;
				}
				arg++;
			}
		}
		copy_cmd = copy_cmd->next;
	}
}
