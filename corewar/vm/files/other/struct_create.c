/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

t_cmd			*create_cmd()
{
	t_cmd		*cmd;
	int			i;

	i = 0;
	cmd = (t_cmd *)malloc(sizeof(t_cmd));
	cmd->cmd_size = 0;
	cmd->cmd_in_hex = 0;
	cmd->coding_byte = 0;
	while (i < 3)
	{
		cmd->arg_types[i] = 0;
		cmd->arg[i] = 0;
	}
	return (cmd);
}

t_file			*create_file(void)
{
	t_file		*file;

	file = malloc(sizeof(t_file));
	file->file_name = NULL;
	file->magic = 0;
	file->prog_name = NULL;
	file->prog_size = 0;
	file->prog_comment = NULL;
	file->player_num = 0;
	file->read = NULL;
	file->commands = NULL;
	file->next = NULL;
	return (file);
}

t_map			*create_map(void)
{
	t_map		*map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_bzero(map->map, MEM_SIZE + 1);
	map->cycle = 0;
	map->cycle_to_die = CYCLE_TO_DIE;
	map->processes = 0;
	map->players = NULL;
	map->flags = NULL;
	map->ps = NULL;
	map->ps_counter = 1;
	map->total_lives = 0;
	return (map);
}

t_ps			*create_ps(int pc, int player, int num)
{
	t_ps		*ps;
	int			i;

	
	ps = (t_ps *)malloc(sizeof(t_ps));
	ps->arg = (int *)malloc(sizeof(int) * MAX_ARGS_NUMBER);
	ps->arg_types = (int *)malloc(sizeof(int) * MAX_ARGS_NUMBER);
	ps->pc = pc;
	i = 0;
	while (i < REG_NUMBER || i < MAX_ARGS_NUMBER)
	{
		if (i < REG_NUMBER)
			ps->reg[i] = 0;
		if (i < MAX_ARGS_NUMBER)
		{
			ps->arg[i] = 0;
			ps->arg_types[i] = 0;
		}
		i++;
	}
	ps->cmd_in_hex = 0;
	ps->coding_byte = 0;
	ps->player_num = player;
	ps->carry = 0;
	ps->check_live = 0;
	ps->cycles_to_cmd = 0;
	ps->p_size = 0;
	ps->ps_num = num;
	ps->skip_cmd = 0;
	ps->next = NULL;
	return (ps);
}

t_flags			*create_flags(void)
{
	t_flags		*flags;

	flags = (t_flags *)malloc(sizeof(t_flags));
	flags->a_flag = 0;
	flags->b_flag = 0;
	flags->d_flag = 0;
	flags->d_value = 0;
	flags->n_flag = 0;
	flags->v_flag = 0;
	flags->v_value = 0;
	flags->s_flag = 0;
	flags->s_value = 0;
	return (flags);
}

t_player		*create_player(void)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	player->name = NULL;
	player->player_num = 0;
	player->total_lives = 0;
	player->last_live = 0;
	player->next = NULL;
	return (player);
}
