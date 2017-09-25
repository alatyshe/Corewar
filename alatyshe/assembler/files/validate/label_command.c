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

static int			check_syntax(t_header *head, char *read)
{
	while (read[head->x] && read[head->x] != '#')
	{
		if (!cmp_char_with_str(read[head->x], AVAILABLE_CHARS))
			return (error_type(head, LEXICAL_ERROR, EMPTY));
		head->x++;
	}
	head->x = skip_spaces(read);
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

int					check_label(t_header *head, t_cmd *command,
	char *read, int fd)
{
	int				error;
	int				i;

	while (read[head->x] && read[head->x] != ':'
		&& read[head->x] != '#' && !ft_isblank(read[head->x]))
		head->x++;
	if (read[head->x] == ':')
	{
		read[head->x++] = '\0';
		i = 0;
		while (read[i])
		{
			if (!cmp_char_with_str(read[i], LABEL_CHARS))
				return (error_type(head, LEXICAL_ERROR, EMPTY));
			i++;
		}
		command->label = ft_strdup(read);
	}
	else if (read[head->x] == '#')
	{
		printf("%s\n", read);
		error_type(head, SYNTAX_ERROR, ENDLINE);
	}
	return (0);
}

int					label_command(t_header *head, char *read, int fd)
{
	t_cmd			*cmd;
	int				i;

	check_syntax(head, read);
	if (head->error == 0 && read[head->x])
	{
		if (read[head->x] == '#')
			return (0);
		cmd = get_last_cmd(head);
		check_label(head, cmd, read, fd);
		if (head->error > 0)
			return (head->x);
		head->x += skip_spaces(read + head->x);
		head->x += get_command(head, cmd, read + head->x, fd);
		if (head->error == 0)
			cmd->next = create_t_cmd();
	}
	return (0);
}
