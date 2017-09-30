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

#include "../header/vm.h"

t_cmd			*create_cmd(int	args)
{
	t_cmd		*new;
	int			i;

	i = 0;
	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->cmd_name = NULL;
	new->cmd_size = 0;
	new->cmd_in_hex = 0;
	new->codage_byte = 0;
	new->arg_types = (char *)malloc(sizeof(char) * args);
	new->arg = (t_arg **)malloc(sizeof(t_arg *) * args);
	new->arg = (t_arg **)malloc(sizeof(t_arg *) * args);
	while (i < args)
		new->arg[i++] = (t_arg *)malloc(sizeof(t_arg));
	new->next = NULL;
	return (new);
}

t_info			*create_info(void)
{
	t_info		*new;

	new = (t_info *)malloc(sizeof(t_info));
	new->file_name = NULL;
	new->magic = 0;
	new->prog_name = NULL;
	new->prog_size = 0;
	new->prog_comment = NULL;
	new->error = 0;
	new->commands = NULL;
	return (new);
}

t_map			*create_map(void)
{
	t_map		*new;

	new = (t_map *)malloc(sizeof(t_map));
	new->cycle = 0;
	new->cycle_to_die = CYCLE_TO_DIE;
	new->cycle_delta = CYCLE_DELTA;
	new->processes = 0;
	new->players = NULL;
	new->ps = NULL;
	return (new);
}

t_player		*create_player(void)
{
	t_player	*new;

	new = (t_player *)malloc(sizeof(t_player));
	new->name = NULL;
	new->player = 0;
	new->player_num = 0;
	new->lives = 0;
	new->last_live = 0;
	return (new);
}