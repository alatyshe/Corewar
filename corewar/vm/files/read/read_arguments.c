/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

t_info			*read_arguments(int argc, char **argv)
{
	int			i;
	t_info		*info;
	t_info		*start;
	int			counter_players;
	t_info		*copy;

	i = 1;
	start = NULL;
	counter_players = 0;
	while (i < argc)
	{
		if (start == NULL)
		{
			info = create_info();
			start = info;
			counter_players++;
		}
		else
		{
			info->next = create_info();
			info = info->next;
			counter_players++;
		}
		read_file(argv[i], info, counter_players);
		i++;
	}
	return (start);
}