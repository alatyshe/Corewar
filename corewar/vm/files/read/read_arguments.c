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

t_file			*read_arguments(int argc, char **argv, int *counter_players)
{
	int			i;
	t_file		*file;
	t_file		*start;
	t_file		*copy;

	i = 1;
	start = NULL;
	while (i < argc)
	{
		if (start == NULL)
		{
			file = create_file();
			start = file;
			(*counter_players)++;
		}
		else
		{
			file->next = create_file();
			file = file->next;
			(*counter_players)++;
		}
		read_file(argv[i], file, *counter_players);
		i++;
	}
	return (start);
}