/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
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
		flags->a_flag = 'a';
	else if (!ft_strcmp(s, "-d"))
	{
		flags->d_flag = 'd';
		flags->d_value = -1;
	}
	else if (!ft_strcmp(s, "-n"))
		flags->n_flag = 'n';
	else if (!ft_strcmp(s, "-v"))
	{
		flags->v_flag = 'v';
		flags->v_value = -1;
	}
	else if (!ft_strcmp(s, "-s"))
	{
		flags->s_flag = 's';
		flags->s_value = -1;
	}
	else if (!ft_strcmp(s, "-java"))
		flags->java_flag = 1;
	else if (!ft_strcmp(s, "-db"))
		flags->db_flag = 1;
	return (0);
}

int				it_is_flag(char *s)
{
	if (!ft_strcmp(s, "-a"))
		return (1);
	else if (!ft_strcmp(s, "-d"))
		return (1);
	else if (!ft_strcmp(s, "-n"))
		return (1);
	else if (!ft_strcmp(s, "-v"))
		return (1);
	else if (!ft_strcmp(s, "-s"))
		return (1);
	else if (!ft_strcmp(s, "-java"))
		return (1);
	else if (!ft_strcmp(s, "-db"))
		return (1);
	return (0);
}

void			num_arg_analysing(char *s, t_flags *f)
{
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

int				check_flags(t_flags *f, char c, int n)
{
	if (f->d_flag == c && f->n_flag == 0
		&& f->java_flag == 0 && f->db_flag == 0)
		return (1);
	else if (f->s_flag == c && f->n_flag == 0 &&
		f->java_flag == 0 && f->db_flag == 0)
		return (1);
	else if (f->v_flag == c && f->n_flag == 0 &&
		f->java_flag == 0)
	{
		if (f->v_value & n)
			return (1);
	}
	return (0);
}
