/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/dcmp.h"

static char		*making_name(char *s, int i, int j)
{
	char	*name;
	char	*name_temp;
	char	*temp;

	name = NULL;
	if (i != 0)
	{
		name = ft_strndup(s, i + 1);
		name_temp = ft_strjoin(name, "dcmp_");
		free(name);
		temp = ft_strndup(&s[i + 1], j - i - 1);
		name = ft_strjoin(name_temp, temp);
		free(temp);
		free(name_temp);
	}
	else
	{
		name_temp = ft_strdup("dcmp_");
		temp = ft_strndup(s, j);
		name = ft_strjoin(name_temp, temp);
		free(name_temp);
		free(temp);
	}
	return (name);
}

char			*create_name_of_file(char *s)
{
	int			i;
	int			j;
	char		*name;
	char		*name_temp;

	i = ft_strlen(s);
	j = i;
	while (s[j] != '.')
		j--;
	while (s[i] != '/' && i != 0)
		i--;
	name = making_name(s, i, j);
	name_temp = ft_strjoin(name, ".s");
	free(name);
	return (name_temp);
}

void			writing_header(int fd, t_file *file)
{
	ft_putstr_fd(".name \"", fd);
	ft_putstr_fd(file->prog_name, fd);
	ft_putstr_fd("\"\n", fd);
	ft_putstr_fd(".comment \"", fd);
	ft_putstr_fd(file->prog_comment, fd);
	ft_putstr_fd("\"\n\n", fd);
}

void			writing_commands(int fd, t_file *file)
{
	t_cmd	*cmd;
	int		argc;
	int		i;

	cmd = file->commands;
	while (cmd)
	{
		ft_putstr_fd(cmd->cmd_name, fd);
		ft_putstr_fd(" ", fd);
		argc = g_tab[cmd->cmd_in_hex - 1].count_arg;
		i = 0;
		while (i < argc)
		{
			if (cmd->arg_types[i] == 1)
				ft_putstr_fd("r", fd);
			else if (cmd->arg_types[i] == 2 || argc == 1)
				ft_putstr_fd("%", fd);
			ft_putnbr_fd(cmd->arg[i], fd);
			if (i < argc - 1)
				ft_putstr_fd(",", fd);
			i++;
		}
		ft_putstr_fd("\n", fd);
		cmd = cmd->next;
	}
}

void			writing_to_file(t_file *file)
{
	char	*name;
	int		fd;

	name = create_name_of_file(file->file_name);
	if (!name)
		return ;
	fd = open(name, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	writing_header(fd, file);
	writing_commands(fd, file);
	ft_printf("Writing output program to %s\n", name);
	free(name);
	close(fd);
}
