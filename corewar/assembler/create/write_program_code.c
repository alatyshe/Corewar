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

int 	write_arg(int fd,t_header *header, t_function *function)
{
	return (0);
}

int		write_function(int fd,t_header *header, t_function *function)
{
	write(fd, &function->func_in_hex, 1);
	write(fd, &function->arg_types, 1);
	write_arg(fd, header, function);
	return (0);
}

int 	write_program(int fd, t_header *header)
{
	t_function	*function;

	function = header->functions;
	while (function)
	{
		write_function(fd, header, function);
		function = function->next;
	}

	return (0);
}

