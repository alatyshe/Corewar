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

#include "../header/asm.h"
#include "../header/create.h"

int						reading_file(t_header *head, int fd)
{
	char				*read;

	while (get_next_line(fd, &read))
	{
		head->x = 0;
		if (head->prog_name == NULL || head->prog_comment == NULL
			|| read[skip_spaces(read)] == '.')
			header(head, read, fd);
		else if (head->prog_name != NULL && head->prog_comment != NULL)
			label_command(head, read, fd);

		if (head->error > 0)
		{
			if (head->error_str == NULL)
				head->error_str = ft_strdup(read + head->x);
			free(read);
			while (1);
			return (error_line_char(head, head->error_str));
		}
		free(read);
		read = NULL;
		head->line++;
	}
	//	фикс!! не учитывает комментарий в последней строке
	if (!check_new_line_at_the_end(fd, &head->x))
	{
		ft_putstr_fd("Syntax error - unexpected end of input", 2);
		ft_putstr_fd("(Perhaps you forgot to end with a newline ?)\n", 2);
	}
	else
		fill_arguments(head, head->commands);
	while(1);
	if (head->error == 0)
	{
		// save in file
		// print_commands(head);
		//create_file(head);
	}
	return (1);
}

int						main(int argc, char **argv)
{
	int					fd;
	t_header			*head;

	head = create_t_header();
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("Error");
			exit(0);
		}
		reading_file(head, fd);
	}
	else
		ft_printf("usage: ./asm file.s\n");
	// while (1);
	return (0);
}
