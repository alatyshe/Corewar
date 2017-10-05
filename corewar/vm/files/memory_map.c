/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/vm.h"

// void			print_map(short *map)
// {
// 	int			i;
// 	short		mask;
// 	int			green_mask;
// 	int			red_mask;
// 	int			blue_mask;
// 	int			cyan_mask;


// 	mask = 255;
// 	green_mask = 256;
// 	red_mask = 512;
// 	blue_mask = 1024;
// 	cyan_mask = 2056;
// 	i = 0;
// 	while (i < MEM_SIZE)
// 	{
// 		if (map[i] & green_mask)
// 			printf("%s", GREEN);
// 		else if (map[i] & red_mask)
// 			printf("%s", RED);
// 		else if (map[i] & blue_mask)
// 			printf("%s", BLUE);
// 		else if (map[i] & cyan_mask)
// 			printf("%s", CYAN);
// 		printf("%02x ", (map[i] & mask));
// 		printf("%s", RESET);
// 		if ((i + 1) % 64 == 0)
// 			printf("\n");
// 		i++;
// 	}
// }

// void			print_wb_map(short *map)
// {
// 	int 	i;
// 	short	mask;

// 	i = 0;
// 	mask = 255;
// 	while (i < MEM_SIZE)
// 	{
// 		printf("%02x ", map[i] & mask);
// 		if ((i + 1) % 64 == 0)
// 			printf("\n");
// 		i++;
// 	}
// }