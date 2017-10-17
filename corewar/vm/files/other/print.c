/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
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

void			print_one_cycle(t_map *map)
{
	int			i;
	short		mask;

	mask = 255;
	i = 0;
	while (i < MEM_SIZE)
	{
		if (i == 0)
			ft_printf("0x0000 : ");
		if (i != 0 && i % 64 == 0)
			ft_printf("%#06x : ", i);
		ft_printf("%02x ", map->map[i] & mask);
		if ((i + 1) % 64 == 0)
			ft_printf("\n");
		i++;
	}
}

void			print_one_cycle_for_j(t_map *map)
{
	int			i;

	i = 0;
	while (i < MEM_SIZE)
	{
		printf("%02x ", map->map[i] & 255);
		i++;
	}
}

void			print_map(t_map *map)
{
	char		*buf;

	buf = NULL;

	if (check_flags(map->flags, 's', 0))
	{
		if (map->cycle % map->flags->s_value == 0)
		{
			print_one_cycle(map);
			get_next_line(0, &buf);
		}
	}
	else if (check_flags(map->flags, 'j', 0))
	{
		print_one_cycle_for_j(map);
	}
}

void			return_color(int n)
{
	if (n == 1)
		printf("%s", RED);
	else if (n == 2)
		printf("%s", GREEN);
	else if (n == 3)
		printf("%s", YELLOW);
	else if (n == 4)
		printf("%s", BLUE);
	else if (n == 5)
		printf("%s", MAGENTA);
	else if (n == 6)
		printf("%s", CYAN);
	else
		printf("%s", BLACK);

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

void			print_flags(t_flags *f)
{
	printf("a_flag:		%d\n", f->a_flag);
	printf("b_flag:		%d\n", f->b_flag);
	printf("d_flag:\t\t%d\td_value\t\t%d\n", f->d_flag, f->d_value);
	printf("n_flag:		%d\n", f->n_flag);
	printf("j_flag:		%c\n", f->j_flag);
	printf("v_flag:\t\t%d\tv_value\t\t%d\n", f->v_flag, f->v_value);
	printf("s_flag:\t\t%d\ts_value\t\t%d\n", f->s_flag, f->s_value);
}

