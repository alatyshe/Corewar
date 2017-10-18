/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/dcmp.h"

void		print_file(t_file *files)
{
	t_file	*f;

	f = files;

	while (f)
	{
		printf("file name: %s\n", f->file_name);
		printf("magic: %d\n", f->magic);
		printf("prog_name: %s\n", f->prog_name);
		printf("prog_size: %d\n", f->prog_size);
		printf("prog_comment: %s\n", f->prog_comment);
		printf("player_num: %d\n", f->player_num);
		printf("read: %s\n", f->read);
		print_cmd(f->commands);
		printf("\n");
		f = f->next;
	}
}

void		print_cmd(t_cmd *cmd)
{
	t_cmd	*c;
	int		i;

	c = cmd;
	i = 0;

	while (c)
	{
		printf("cmd_name: %s\n", c->cmd_name);
		printf("cmd_size: %d\n", c->cmd_size);
		printf("cmd_in_hex: %x\n", c->cmd_in_hex);
		printf("coding_byte: %x\n", c->coding_byte);
		while (i < 3)
		{
			printf("arg_types: %c\n", c->arg_types[i]);
			i++;
		}
		i = 0;
		while (i < 3)
		{
			printf("arg: %d\n", c->arg[i]);
			i++;
		}
		c = c->next;
	}
}
