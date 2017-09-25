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
	// лейбл не найден
	printf("fill_label_distance : HERRRROR\n");
	return (0);
}

int					fill_cmd_arg(t_header *head, t_cmd *cmd, char *str, int arg_num)
{
	int				x;

	x = skip_spaces(str);
	if (str[x] == '%')
	{
		x++;
		if (str[x] == ':')
			cmd->arg[arg_num]->num = fill_label_distance(head, str + x + 1, cmd);
		else
			cmd->arg[arg_num]->num = ft_atoi(str + x);
	}
	else if (str[x] == 'r')
	{
		x++;
		if (str[x] == ':')
			cmd->arg[arg_num]->num = fill_label_distance(head, str + x + 1, cmd);
		else
			cmd->arg[arg_num]->num = ft_atoi(str + x);
	}
	else if ((g_tab[cmd->cmd_in_hex - 1].arg[arg_num] & T_IND) && ft_isdigit(str[x]))
		cmd->arg[arg_num]->shrt = ft_atoi(str + x);
	else
		printf("ERROR\n");
	while (str[x] && str[x] != ',')
		x++;
	x++;
	x += skip_spaces(str + x);
	return (x);
}

void				fill_arguments(t_header *head, t_cmd *cmd)
{
	t_cmd			*copy;
	int				arg;
	int				x;

	copy = cmd;
	while (copy->next)
	{
		arg = 0;
		x = skip_spaces(copy->str);
		head->prog_size += copy->cmd_size;
		while (arg < g_tab[copy->cmd_in_hex - 1].count_arg)
		{
			x += fill_cmd_arg(head, copy, copy->str + x, arg);
			arg++;
		}
		copy = copy->next;
	}
}
