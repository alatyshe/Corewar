/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 16:01:24 by coleksii          #+#    #+#             */
/*   Updated: 2017/09/12 16:02:06 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/create.h"

int 	write_arg(int fd, t_header *header, t_cmd *cmd)
{
	return (0);
}

int		write_cmd(int fd,t_header *header, t_cmd *cmd)
{
	write(fd, &cmd->cmd_in_hex, 1);
	write(fd, &cmd->arg_types, 1);
	write_arg(fd, header, cmd);
	return (0);
}

int 	write_program(int fd, t_header *header)
{
	t_cmd	*cmd;

	cmd = header->commands;
	while (cmd)
	{
		write_cmd(fd, header, cmd);
		cmd = cmd->next;
	}

	return (0);
}

