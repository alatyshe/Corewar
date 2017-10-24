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

t_file			*filling_files(t_file *start, int *counter_players, char *s)
{
	t_file		*file;

	if (start == NULL)
	{
		start = create_file();
		(*counter_players)++;
		read_file(s, start, *counter_players);
	}
	else
	{
		file = start;
		while (file->next)
			file = file->next;
		file->next = create_file();
		file = file->next;
		(*counter_players)++;
		read_file(s, file, *counter_players);
	}
	return (start);
}

t_file			*read_prog_argv(int argc, char **argv,
	int *counter_players, t_flags *f)
{
	int			i;
	t_file		*start;
	int			flag_return;

	i = 1;
	flag_return = 0;
	start = NULL;
	while (i < argc)
	{
		if (isdigit_str(argv[i]))
			num_arg_analysing(argv[i], f);
		else if (it_is_flag(argv[i]))
			filling_flags(argv[i], f);
		else
			start = filling_files(start, counter_players, argv[i]);
		i++;
	}
	min_arg_value(f);
	return (start);
}
