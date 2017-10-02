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

int				main(int argc, char **argv)
{
	int			i;
	t_info		*info;
	t_info		*begin;
	t_player	*player;
	t_player	*first_player;

	i = 1;
	info = create_info();
	player = create_player();
	first_player = player;
	begin = info;
	while (i < argc)
	{
		if (info == NULL)
			info = create_info();
		if (player == NULL)
			player = create_player();
		read_file(argv[i], info);
		player->player_num = i;
		player->name = ft_strdup(info->prog_name);
		player = player->next;
		info = info->next;
		i++;
	}
	filling_map(begin, first_player, i - 1);
	return (0);
}
