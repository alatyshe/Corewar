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


int main()
{
	t_header	*header;
	t_cmd		*cmd;

	
	header = (t_header *)malloc(sizeof(t_header));
	header->magic = 0xea83f3;
	header->prog_comment = "some comment";
	header->prog_name = "some prog namea";
	header->prog_size = 7;
	header->error = 0;
	header->file_name = "some_file.cor";


	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	header->commands = cmd;
	cmd->str= "live";
	cmd->cmd_in_hex = 0x01;
	cmd->label = "label";
	cmd->arg_types = 0x1;

	ft_printf("%s", "hello main\n");

	create_file(header);
	return (0);
}
