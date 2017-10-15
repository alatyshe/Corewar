/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coleksii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 19:46:26 by coleksii          #+#    #+#             */
/*   Updated: 2017/10/03 19:51:57 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

int		write_revers_bytes(int fd, int byte)
{
	int a;

	a = 0;
	a = a | (byte << 24);
	a = a | ((0x0000FF00 & byte) << 8);
	a = a | ((0x00FF0000 & byte) >> 8);
	a = a | ((0xFF000000 & byte) >> 24);
	write(fd, &a, 4);
	return (0);
}

int		write_first(int fd, t_header *header)
{
	int a;
	int len;
	int zero;

	a = 0xf383ea00;
	len = ft_strlen(header->prog_name);
	write(fd, &a, 4);
	write(fd, header->prog_name, len);
	a = 132 - len;
	zero = 0;
	while (a-- > 0)
		write(fd, &zero, 1);
	write_revers_bytes(fd, header->prog_size);
	len = ft_strlen(header->prog_comment);
	write(fd, header->prog_comment, len);
	a = 2052 - len;
	while (a-- > 0)
		write(fd, &zero, 1);
	return (0);
}

int		file_name(t_header *header)
{
	char	*s;
	int		i;

	i = ft_strlen(header->file_name);
	if (header->file_name[i - 1] != 's' || header->file_name[i - 2] != '.')
		return (0);
	s = (char *)malloc(sizeof(char) * (i + 3));
	s = ft_strcpy(s, header->file_name);
	s[i + 2] = '\0';
	s[i + 1] = 'r';
	s[i] = 'o';
	s[i - 1] = 'c';
	s[i - 2] = '.';
	free(header->file_name);
	header->file_name = s;
	return (1);
}

int		create_file(t_header *header)
{
	int fd;

	if (!file_name(header))
		return (0);
	fd = open(header->file_name, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	write_first(fd, header);
	write_program(fd, header);
	return (0);
}
