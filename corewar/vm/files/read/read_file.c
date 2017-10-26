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

static unsigned int	fill_file_struct(unsigned char *buf, int file_len,
	t_file *file, char *file_name)
{
	unsigned int	j;

	j = 0;
	j = read_header(buf, file, file_name);
	if ((file_len - j) != file->prog_size)
	{
		ft_putstr_fd("Error: File ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd(" has a code ", 2);
		ft_putstr_fd("size that differ from what its header says\n", 2);
		exit(0);
	}
	return (file->prog_size);
}

void				read_file(char *file_name, t_file *file, int player_num)
{
	unsigned char	*buf;
	unsigned long	file_len;
	int				cmd_len;
	int				fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Can't read source file ", 2);
		ft_putstr_fd(file_name, 2);
		ft_putstr_fd("\n", 2);
		exit(0);
	}
	file_len = lseek(fd, 0, SEEK_END);
	file->player_num = player_num * -1;
	lseek(fd, 0, SEEK_SET);
	buf = malloc(sizeof(unsigned char) * file_len + 1);
	read(fd, buf, file_len);
	cmd_len = fill_file_struct(buf, file_len, file, file_name);
	file->read = malloc(sizeof(unsigned char) * cmd_len + 1);
	lseek(fd, -cmd_len, 2);
	read(fd, file->read, cmd_len);
	free(buf);
	close(fd);
}
