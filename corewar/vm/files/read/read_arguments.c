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

void			min_arg_value(t_flags *f)
{
	if (f->d_value == -1 || f->v_value == -1 || f->s_value == -1)
	{
		ft_putstr_fd("Invalid flags\n", 2);
		exit(0);
	}
}

int				filling_flags(char *s, t_flags *flags)
{
	min_arg_value(flags);
	if (!ft_strcmp(s, "-a"))
		flags->a_flag = 1;
	else if (!ft_strcmp(s, "-b"))
		flags->b_flag = 1;
	else if (!ft_strcmp(s, "-d"))
	{
		flags->d_flag = 1;
		flags->d_value = -1;
	}
	else if (!ft_strcmp(s, "-n"))
		flags->n_flag = 1;
	else if (!ft_strcmp(s, "-v"))
	{
		flags->v_flag = 1;
		flags->v_value = -1;
	}
	else if (!ft_strcmp(s, "-s"))
	{
		flags->s_flag = 1;
		flags->s_value = -1;
	}
	return (0);
}

int				it_is_flag(char *s)
{
	if (!ft_strcmp(s, "-a"))
		return (1);
	else if (!ft_strcmp(s, "-b"))
		return (1);
	else if (!ft_strcmp(s, "-d"))
		return (1);
	else if (!ft_strcmp(s, "-n"))
		return (1);
	else if (!ft_strcmp(s, "-v"))
		return (1);
	else if (!ft_strcmp(s, "-s"))
		return (1);
	return (0);
}

void			num_arg_analysing(char *s, t_flags *f)
{
	int		i;

	if (f->d_value == -1)
		f->d_value = ft_atoi(s);
	else if (f->v_value == -1)
		f->v_value = ft_atoi(s);
	else if (f->s_value == -1)
		f->s_value = ft_atoi(s);
	else
	{
		ft_putstr_fd("Can't read source file ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd("\n", 2);
		exit(0);
	}

}

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

t_file			*read_arguments(int argc, char **argv, int *counter_players, t_flags *f)
{
	int			i;
	t_file		*file;
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