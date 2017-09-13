/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:00:41 by alatyshe          #+#    #+#             */
/*   Updated: 2017/03/29 16:00:44 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/asm.h"

t_header				*reading_file(int fd)
{
	char				*str;
	t_header			*head;
	int					x;

	head = create_t_header();
	x = 0;
	while (get_next_line(fd, &str))
	{
		if (head->prog_name == NULL || head->prog_comment == NULL)
			x = check_comment_name(head, str, fd);
		else if (head->prog_name != NULL && head->prog_comment != NULL)
			;
		if (head->error > 0)
		{
			if (head->error_string == NULL)
				head->error_string = str;
			return (error_message_y_x(head, head->line, x, head->error_string));
		}
		free(str);
		str = NULL;
		head->line++;
	}
	if (!check_new_line_at_the_end(fd, &x))
	{
		ft_putstr_fd("Syntax error - unexpected end of input", 2);
		ft_putstr_fd("(Perhaps you forgot to end with a newline ?)\n", 2);
	}
	// check_info()
	return (head);
}

void					valid_name(t_header *head, char *str)
{
	printf("%s\n", str);
}

int						main(int argc, char **argv)
{
	int					fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("Error");
			exit(0);
		}
		reading_file(fd);
	}
	else
		ft_printf("usage: ./asm file.s\n");
	return (0);
}
