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
	while (read[i] && read[i] != ':'
		&& read[i] != '#' && !ft_isblank(read[i]))
		i++;
	if (read[i] == ':')
	{
		read[i++] = '\0';
		x = check_syntax(head, read, LABEL_CHARS);
		if (head->error > 0)
			return ;
		x++;
		command->label = ft_strdup(read);
	}
	else if (read[i] == '#')
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
	if (head->error == 0 && read[head->x])
	{
		if (read[head->x] == '#')
			return ;
		cmd = get_last_cmd(head);
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
