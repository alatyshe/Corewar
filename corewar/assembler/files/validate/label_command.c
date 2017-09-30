/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int					get_label_distance(t_header *head, char *to_find, t_cmd *position)
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

t_cmd				*get_last_cmd(t_header *head)
{
	t_cmd			*cmd;

	if (head->commands)
	{
		cmd = head->commands;
		while (cmd->next)
			cmd = cmd->next;
		return (cmd);
	}
	else
		head->commands = create_t_cmd();
	return (head->commands);
}

void				label(t_header *head, t_cmd *command,
	char *read, int fd)
{
	int				error;
	int				i;
	int				x;

	i = 0;
	x = 0;
	while (read[i] && read[i] != LABEL_CHAR
		&& read[i] != COMMENT_CHAR && !ft_isblank(read[i]))
		i++;
	if (read[i] == LABEL_CHAR)
	{
		read[i++] = '\0';
		x = check_syntax(head, read, LABEL_CHARS);
		if (head->error > 0)
			return ;
		x++;
		command->label = ft_strdup(read);
	}
	else if (read[i] == COMMENT_CHAR)
	{
		head->x += ft_strlen(read);
		error_type(head, SYNTAX_ERROR, ENDLINE);
		return ;
	}
	head->x += x;
}

void				label_command(t_header *head, char *read, int fd)
{
	t_cmd			*cmd;
	int				i;

	head->x = skip_spaces(read);
	check_syntax(head, read, AVAILABLE_CHARS);
	if (head->error == 0 && read)
	{
		if (read[head->x] == COMMENT_CHAR)
			return ;
		cmd = get_last_cmd(head);
		cmd->line = head->line;
		head->last_cmd_line = cmd->line;
		label(head, cmd, read + head->x, fd);
		if (head->error > 0)
			return ;
		head->x += skip_spaces(read + head->x);
		command(head, cmd, read + head->x);
		if (head->error > 0 || (cmd->label == NULL && cmd->str == NULL))
			return ;
		cmd->next = create_t_cmd();
	}
}
