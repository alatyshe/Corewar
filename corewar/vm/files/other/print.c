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

void			print_buf(unsigned char *buffer, int buffer_size)
{
	int		i;

	i = 0;
	while (i < buffer_size)
	{
		printf("[%x]", buffer[i]);
		i++;
	}
	printf("\n");
}

void			print_file(t_file *file)
{
	printf("%s===============================%s\n", GREEN, RESET);
	printf("fileName :\t|%s|\n", file->file_name);
	printf("magic :\t\t%x\n", file->magic);
	printf("progName:\t|%s|\n", file->prog_name);
	printf("prog_size:\t%d\n", file->prog_size);
	printf("prog_comment:\t|%s|\n", file->prog_comment);
	printf("player_num:\t|%d|\n", file->player_num);
	print_buf(file->read, file->prog_size);
	printf("%s===============================%s\n\n", GREEN, RESET);
}

// void			print_cmd(t_cmd *cmd)
// {
// 	int			i;

// 	printf("%s===============================%s\n", RED, RESET);
// 	printf("%scmd_name: %s\n%s", MAGENTA, cmd->cmd_name, RESET);
// 	printf("cmd_size :\t%d\n", cmd->cmd_size);
// 	printf("cmd_in_hex :\t%02x\n", cmd->cmd_in_hex);
// 	printf("coding_byte:\t%02x\n\n", cmd->coding_byte);
// 	i = 0;
// 	while (i < g_tab[cmd->cmd_in_hex - 1].count_arg)
// 	{
// 		printf("argument[%d]:\t%-10x", i + 1, cmd->arg[i]);
// 		printf("%sTYPE : %s", GREEN, RESET);
// 		if (cmd->arg_types[i] == T_REG)
// 			printf("T_REG");
// 		else if (cmd->arg_types[i] == T_DIR)
// 			printf("T_DIR");
// 		else if (cmd->arg_types[i] == T_IND)
// 			printf("T_IND");
// 		printf("\n");
// 		i++;
// 	}
// 	printf("%s===============================%s\n", RED, RESET);
// }

void			print_process(t_ps *ps)
{
	int			i;

	i = 0;
	printf("%s==============================================%s\n", YELLOW, RESET);
	printf("PS->ProgramCounter:\t%d\n", ps->pc);
	printf("\t\tREGISTERS\n");
	while (i < 16)
	{
		printf("%5.2d    ", i + 1);
		i++;
	}
	printf("\n");
	i = 0;
	while (i < 16)
	{
		printf("%08x ", ps->reg[i]);
		i++;
	}
	printf("\n\n");
	printf("ps->cmd_in_hex:\t\t%02x\n", ps->cmd_in_hex);
	printf("ps->coding_byte:\t%x\n", (ps->coding_byte & 125));
	i = 0;
	printf("ARG_TYPES :\t");
	while (i < MAX_ARGS_NUMBER)
	{
		printf("% 4d ", ps->arg_types[i]);
		i++;
	}
	printf("\nARGUMENTS :\t");
	i = 0;
	while (i < MAX_ARGS_NUMBER)
	{		
		printf("%04x ", ps->arg[i]);
		i++;
	}
	printf("\nps->player_num:\t\t%d\n", ps->player_num);
	printf("ps->carry:\t\t%d\n", ps->carry);
	printf("ps->cycles_to_cmd:\t%d\n", ps->cycles_to_cmd);
	printf("ps->check_live:\t\t%d\n", ps->check_live);
	printf("ps->p_size:\t\t%d\n", ps->p_size);
	printf("%s==============================================%s\n\n", YELLOW, RESET);  
}

void			print_processes(t_ps *ps)
{
	t_ps		*copy_ps;

	copy_ps = ps;
	while (copy_ps)
	{
		print_process(copy_ps);
		copy_ps = copy_ps->next;
	}
}

void			print_players(t_player *player)
{
	
	while (player)
	{
		printf("%sPLAYER START PLAYER START PLAYER START PLAYER START%s\n", MAGENTA, RESET);
		printf("%sPLAYER->NAME:%s\t\t%s\n", GREEN, RESET, player->name);
		printf("%sPLAYER->PLAYER_NUM:%s\t%d\n", GREEN, RESET, player->player_num);
		printf("%sPLAYER->LAST_LIVE:%s\t%d\n", GREEN, RESET, player->last_live);
		printf("%sPLAYER->TOTAL_LIVES:%s\t%d\n", GREEN, RESET, player->total_lives);
		printf("\n");
		printf("%sPROCESS PROCESS PROCESS PROCESS PROCESS PROCESS PROCESS%s\n", CYAN, RESET);
		printf("%sPLAYER END PLAYER END PLAYER END PLAYER END PLAYER END PLAYER END PLAYER END PLAYER END%s\n\n\n", MAGENTA, RESET);
		player = player->next;
	}
}	

void			print_one_cycle(t_map *map)
{
	int		i;
	short	mask;

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
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		printf("%02x ", map->map[i] & 255);
		i++;
	}
}


void			print_info_map(t_map *map)
{

	printf("cycle:\t\t%d\n", map->cycle);
	printf("cycle_to_die:\t\t%d\n", map->cycle_to_die);
	printf("total_lives:\t\t%d\n", map->total_lives);
	printf("processes:\t\t%d\n", map->processes);
	printf("ps_counter:\t\t%d\n\n", map->ps_counter);
}

void			print_map(t_map *map)
{
	char	*buf;

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

void				return_color(int n)
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

void				introducing_print(t_file *file)
{
	t_file	*player;
	int		i;

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

void				print_flags(t_flags *f)
{
	printf("a_flag:		%d\n", f->a_flag);
	printf("b_flag:		%d\n", f->b_flag);
	printf("d_flag:\t\t%d\td_value\t\t%d\n", f->d_flag, f->d_value);
	printf("n_flag:		%d\n", f->n_flag);
	printf("j_flag:		%c\n", f->j_flag);
	printf("v_flag:\t\t%d\tv_value\t\t%d\n", f->v_flag, f->v_value);
	printf("s_flag:\t\t%d\ts_value\t\t%d\n", f->s_flag, f->s_value);
}

