/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_java_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void			print_map_java(t_map *map, t_file *file)
{
	int			i;
	int			players;
	t_file		*copy_file;

	i = 0;
	players = 1;
	copy_file = file;
	while (copy_file)
	{
		ft_printf("%d:%d:", players, copy_file->prog_size);
		ft_printf("%s:%s;", copy_file->prog_name, copy_file->prog_comment);
		copy_file = copy_file->next;
		players++;
	}
	ft_printf("\n");
	while (i < MEM_SIZE)
		ft_printf("%02x ", 255 & map->map[i++]);
	ft_printf("\n");
}
