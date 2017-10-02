/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

t_cmd				*create_t_cmd(void)
{
	t_cmd			*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->label = NULL;
	cmd->line = 0;
	cmd->x = 0;
	cmd->str = NULL;
	cmd->size = 0;
	cmd->code = -1;
	cmd->arg_types = 0;
	cmd->arg = (t_arg **)malloc(sizeof(t_arg *) * 3);
	cmd->arg[0] = create_t_arg();
	cmd->arg[1] = create_t_arg();
	cmd->arg[2] = create_t_arg();
	cmd->next = NULL;
	return (cmd);
}

t_arg				*create_t_arg(void)
{
	t_arg			*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->num = 0;
	return (arg);
}

t_header			*create_t_header(void)
{
	t_header		*header;

	header = (t_header *)malloc(sizeof(t_header));
	header->file_name = NULL;
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_name = NULL;
	header->last_cmd_line = 0;
	header->prog_size = 0;
	header->prog_comment = NULL;
	header->error = 0;
	header->error_str = NULL;
	header->line = 1;
	header->x = 0;
	header->commands = NULL;
	return (header);
}
