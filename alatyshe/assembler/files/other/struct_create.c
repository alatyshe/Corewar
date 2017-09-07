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

t_functions			*create_t_functions()
{
	t_functions		*functions;

	functions = (t_functions *)malloc(sizeof(t_functions));
	functions->name = NULL;
	functions->next = NULL;
	return (functions);
}

t_label				*create_t_label()
{
	t_label			*label;

	label = (t_label *)malloc(sizeof(t_label));
	label->name = NULL;
	label->functions = NULL;
	label->next = NULL;
	return (label);
}

t_header			*create_t_header()
{
	t_header		*header;
	
	header = (t_header *)malloc(sizeof(t_header));

	header->fillness_data = 0;
	header->error = 0;
	header->magic = COREWAR_EXEC_MAGIC;
	header->prog_size = 0;
	header->labels = NULL;
	header->prog_name = ft_strnew(((PROG_NAME_LENGTH + 1) / 4) * 4 + 4);
	header->comment = ft_strnew(((COMMENT_LENGTH + 1) / 4 ) * 4 + 4);
	return (header);
}