

#include "../../header/create.h"

int 	write_revers_bytes(int fd, int byte)
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


int		write_first(int fd, t_header * header)
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

int		create_file(t_header *header)
{
	int fd;

	fd = open(header->file_name, O_RDWR|O_CREAT|O_TRUNC , S_IRUSR|S_IWUSR);
	write_first(fd, header);
	write_program(fd, header);
	return (0);
}