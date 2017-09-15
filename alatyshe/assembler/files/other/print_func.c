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

#include "../../header/other.h"

void				print_functions(t_header *head)
{
	t_function		*function;

	function = head->functions;
	while (function->next)
	{
		printf("%s=====================================================%s\n", GREEN, RESET);
		printf("function->label :\t%s\n", function->label);
		printf("function->name :\t%s\n", function->name);
		printf("function->func_size :\t%d\n", function->func_size);
		printf("function->func_in_hex :\t%d\n", function->func_in_hex);
		printf("function->arg_types :\t%d\n", function->arg_types);
		printf("function->arg_1 :\t%ld\n", function->arg_1->num);
		printf("function->arg_2 :\t%ld\n", function->arg_2->num);
		printf("function->arg_3 :\t%ld\n", function->arg_3->num);
		printf("%s=====================================================%s\n\n", RED, RESET);
		function = function->next;
	}
}
