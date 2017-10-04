/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static int			read_header(unsigned char *buf, t_info *info, char *file)
{
	int				j;

	info->file_name = ft_strdup(file);
	info->magic = magic_reading(buf, info);
	info->prog_name = name_reading(buf, info);
	info->prog_size = size_reading(buf, info);
	info->prog_comment = comment_reading(buf, info);
	j = sizeof(unsigned int) + PROG_NAME_LENGTH + 1;
	while (j % 4 != 0)
		j++;
	j = j + sizeof(unsigned int) + COMMENT_LENGTH + 1;
	while (j % 4 != 0)
		j++;
	return (j);
}

static unsigned int	fill_info_struct(unsigned char *buf, int file_len,
	t_info *info, char *file)
{
	int				j;
	int				prog_size;

	j = 0;
	prog_size = 0;
	j = read_header(buf, info, file);
	prog_size = read_commands(buf, info->commands, j, file_len) - j; // нафига оно нужно - не понятно
	if (prog_size != info->prog_size)
	{
		ft_putstr_fd("Error: File ../../ex.cor has a code ", 2);
		ft_putstr_fd("size that differ from what its header says\n", 2);
		exit(0);
	}
	return (prog_size);
}

void				read_file(char *file, t_info *info, int player_num)
{
	unsigned char	*buf;
	unsigned long	file_len;
	int				cmd_len;
	int				fd;

	fd = open(file, O_RDONLY);
	file_len = lseek(fd, 0, SEEK_END);
	info->player_num = player_num * -1;
	lseek(fd, 0, SEEK_SET);
	buf = malloc(sizeof(unsigned char) * file_len + 1);
	read(fd, buf, file_len);
	cmd_len = fill_info_struct(buf, file_len, info, file);
	info->read = malloc(sizeof(unsigned char) * cmd_len + 1);
	lseek(fd, -cmd_len, 2);
	read(fd, info->read, cmd_len);
	free(buf);
	close(fd);
}
