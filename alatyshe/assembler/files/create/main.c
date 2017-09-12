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

#include "../../header/asm.h"

int main()
{
	t_header *header;

	header = (t_header *)malloc(sizeof(t_header));
	header->magic = 0xea83f3;
	header->prog_comment = "some comment";
	header->prog_name = "some prog name";
	header->prog_size = 0;
	header->error = 0;
	ft_printf("%s", "hello");

	return (0);
}
