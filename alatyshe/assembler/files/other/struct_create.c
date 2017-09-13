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

#include "../../header/other.h"

t_label				*create_t_label()
{
	t_label			*label;

	label = (t_label *)malloc(sizeof(t_label));
	label->label_name = NULL;
	label->label_size = 0;
	label->functions = NULL;
	label->next = NULL;
	return (label);
}

t_function			*create_t_function()
{
	t_function		*function;

	function = (t_function *)malloc(sizeof(t_function));
	function->name = NULL;
	function->func_in_hex = 0;
	function->arg_types = 0;
	function->arg_1 = NULL;
	function->arg_2 = NULL;
	function->arg_3 = NULL;
	function->next_func = NULL;
	return (function);
}

t_arg				*create_t_arg()
{
	t_arg			*arg;

	arg = (t_arg *)malloc(sizeof(t_arg));
	arg->num = 0;
	return (arg);
}

t_header			*create_t_header()
{
	t_header		*header;
	
	header = (t_header *)malloc(sizeof(t_header));
	header->file_name = NULL;
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	header->labels = NULL;
	header->prog_name = NULL;
	// ft_strnew(((PROG_NAME_LENGTH + 1) / 4) * 4 + 4);
	header->prog_comment = NULL;
	header->line = 1;
	header->error = 0;
	header->error_string = NULL;
	// ft_strnew(((COMMENT_LENGTH + 1) / 4 ) * 4 + 4);
	return (header);
}
