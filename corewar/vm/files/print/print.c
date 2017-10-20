/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by alatyshe          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

void			print_usage(void)
{
	ft_printf("Usage: ./corewar [-d N -s N -v N | -b --stealth | -n --stealth] [-a] <champion1.cor> <...>\n");
	ft_printf("-a        : Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("#### TEXT OUTPUT MODE ##########################################################\n");
	ft_printf("-d N      : Dumps memory after N cycles then exits\n");
	ft_printf("-s N      : Runs N cycles, dumps memory, pauses, then repeats\n");
	ft_printf("-v N      : Verbosity levels, can be added together to enable several\n");
	ft_printf("\t- 0 : Show only essentials\n");
	ft_printf("\t- 1 : Show lives\n");
	ft_printf("\t- 2 : Show cycles\n");
	ft_printf("\t- 4 : Show operations (Params are NOT litteral ...)\n");
	ft_printf("\t- 8 : Show deaths\n");
	ft_printf("\t- 16 : Show PC movements (Except for jumps)\n");
	ft_printf("#### BINARY OUTPUT MODE ########################################################\n");
	ft_printf("-b        : Binary output mode for corewar.42.fr\n");
	ft_printf("--stealth : Hides the real contents of the memory\n");
	ft_printf("#### NCURSES OUTPUT MODE #######################################################\n");
	ft_printf("-n        : Ncurses output mode\n");
	ft_printf("--stealth : Hides the real contents of the memory\n");
	ft_printf("################################################################################\n");
}

void			introducing_print(t_file *file)
{
	t_file		*player;
	int			i;

	i = 1;
	player = file;
	ft_printf("Introducing contestants...\n");
	while (player)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			i, player->prog_size, player->prog_name, player->prog_comment);
		i++;
		player = player->next;
	}
}
