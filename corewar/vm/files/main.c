/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

void				mem_copy(short *str1, unsigned char *str2, int len, short mask_col)
{
	while (len)
	{
		*str1 = *str2;
		*str1 = *str1 | mask_col;
		*str1++;
		*str2++;
		len--;
	}
}

void				memory_map(t_info *info, int total_players)
{
	t_map			*map;
	int				pos;
	int				distance;
	short			mask;

	map = create_map();
	pos = 0;
	mask = 1;
	mask = mask << 8;
	distance = MEM_SIZE / total_players;
	while(info)
	{
		mem_copy(map->map + pos, info->read, info->prog_size, mask);
		mask = mask << 1;
		printf("%d\n", mask);
		pos += distance;
		info = info->next;
	}
	print_map(map->map);
}

int				main(int argc, char **argv)
{
	t_info		*files;
	t_info		*copy_files;
	int			count_players;

	files = NULL;
	files = read_arguments(argc, argv);
	count_players = 0;
	copy_files = files;
	while (copy_files)
	{
		// mprint_info(copy_files);
		copy_files = copy_files->next;
		count_players++;
	}
	memory_map(files, count_players);
	return (0);
}
