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

unsigned int		get_value_from_file(void *buf, int len)
{
	int				j;
	unsigned int	res;

	j = 0;
	res = 0;
	while (j < len)
		res = (res << 8) | (((char *)buf)[j++] & 0x000000ff);
	return (res);
}

t_file				*filling_files(t_file *start, int *counter_players, char *s)
{
	t_file			*file;

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

static void			check_num_files(int n)
{
	if (n > MAX_PLAYERS)
	{
		ft_putstr_fd("Too many champions\n", 2);
		exit(0);
	}
}

t_file				*read_prog_argv(int argc, char **argv,
	int *counter_players, t_flags *f)
{
	int				i;
	t_file			*start;
	int				flag_return;
	int				count_files;

	i = 1;
	count_files = 0;
	flag_return = 0;
	start = NULL;
	while (i < argc)
	{
		if (isdigit_str(argv[i]))
			num_arg_analysing(argv[i], f);
		else if (it_is_flag(argv[i]))
			filling_flags(argv[i], f);
		else
		{
			start = filling_files(start, counter_players, argv[i]);
			count_files++;
		}
		i++;
	}
	check_num_files(count_files);
	min_arg_value(f);
	return (start);
}
