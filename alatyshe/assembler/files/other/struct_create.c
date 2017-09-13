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

t_label				*create_t_label(void)
{
	t_label			*label;

	label = (t_label *)malloc(sizeof(t_label));
	label->label_name = NULL;
	label->label_size = 0;
	label->functions = NULL;
	label->prev = NULL;
	label->next = NULL;
	return (label);
}

t_function			*create_t_function(void)
{
	t_function		*function;

	function = (t_function *)malloc(sizeof(t_function));
	function->name = NULL;
	function->func_in_hex = 0;
	function->arg_types = 0;
	function->arg_1 = NULL;
	function->arg_2 = NULL;
	function->arg_3 = NULL;
	function->prev_func = NULL;
	function->next_func = NULL;
	return (function);
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
	header->prog_size = 0;
	header->labels = NULL;
	header->prog_name = NULL;
	header->prog_comment = NULL;
	header->line = 1;
	header->error = 0;
	header->error_string = NULL;
	return (header);
}
