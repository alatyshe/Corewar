/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

void				print_commands(t_header *head)
{
	t_cmd			*cmd;

	cmd = head->commands;
	printf("head->prog_size : %x\n", head->prog_size);
	if (cmd)
		while (cmd->next)
		{
			printf("%s=====================================%s\n", GREEN, RESET);
			printf("cmd->label :\t|%s|\n", cmd->label);
			printf("cmd->line :\t|%d|\n", cmd->line);
			printf("cmd->cmd_size :\t|%d|\n", cmd->cmd_size);
			printf("cmd->str :\t\t|%s|\n", cmd->str);
			printf("\n");
			printf("%02x", cmd->cmd_in_hex);
			if (g_tab[cmd->cmd_in_hex - 1].coding_byte == 1)
				printf("%x", cmd->arg_types);
			printf("|%02x|", cmd->arg[0]->num);
			if (g_tab[cmd->cmd_in_hex - 1].count_arg > 1)
				printf("|%02x|", cmd->arg[1]->num);
			if (g_tab[cmd->cmd_in_hex - 1].count_arg > 2)
				printf("|%02x|", cmd->arg[2]->num);
			printf("\n%s===================================%s\n\n", RED, RESET);
			cmd = cmd->next;
		}
}
