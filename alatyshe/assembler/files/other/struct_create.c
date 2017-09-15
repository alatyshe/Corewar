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

// t_label				*create_t_label(void)
// {
// 	t_label			*label;

// 	label = (t_label *)malloc(sizeof(t_label));
// 	label->label_name = NULL;
// 	label->label_size = 0;
// 	label->functions = NULL;
// 	label->prev = NULL;
// 	label->next = NULL;
// 	return (label);
// }

t_function			*create_t_function(void)
{
	t_function		*function;

	function = (t_function *)malloc(sizeof(t_function));
	//имя лейблы если есть
	function->label = NULL;
	//имя функции и полный размер выделяемой памяти
	function->name = NULL;
	function->func_size = 0;
	//кодировка функции и кодировка аргументов
	function->func_in_hex = 0;
	function->arg_types = 0;

	function->arg_1 = create_t_arg();
	function->arg_2 = create_t_arg();
	function->arg_3 = create_t_arg();

	function->prev = NULL;
	function->next = NULL;
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
	header->prog_name = NULL;
	header->prog_size = 0;
	header->prog_comment = NULL;
	
	header->error = 0;
	header->line = 1;
	header->error_string = NULL;
	header->functions = NULL;
	return (header);
}
