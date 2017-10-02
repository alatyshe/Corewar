/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/vm.h"

static void			fill_player_struct(void *buf, int buf_size,
	t_info *info, char *file)
{
	int				j;

	j = 0;
	info->file_name = ft_strdup(file);
	info->magic = magic_reading(buf, info);
	info->prog_name = name_reading(buf, info);
	info->prog_size = size_reading(buf, info);
	info->prog_comment = comment_reading(buf, info);
	print_info(info);
	j = sizeof(unsigned int) + PROG_NAME_LENGTH + 1;
	while (j % 4 != 0)
		j++;
	j = j + sizeof(unsigned int) + COMMENT_LENGTH + 1;
	while (j % 4 != 0)
		j++;
	info->commands = cmd_reading(buf, info->commands, j);
}

void				read_file(char *file, t_info *info)
{
	void			*buf;
	unsigned long	file_len;
	int				fd;

	// printf("file: %s\n", file);
	fd = open(file, O_RDONLY);
	file_len = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	buf = (unsigned char *)malloc(sizeof(unsigned char) * file_len + 1);
	read(fd, buf, file_len);
	// print_buf(buf, file_len);
	fill_player_struct(buf, file_len, info, file);
	close(fd);
}
