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

// int					check_commands(char *str)
// {
// 	int				i;
// 	i = skip_spaces(str);
// 	if ()


// }

void				reading_file(int fd)
{
	char			*read;
	t_header		*info;


	info = create_t_header();
	while (get_next_line(fd, &read))
	{
		printf("%s\n", read);
	}
}

int					main(int argc, char **argv)
{
	int				fd;

	t_functions		func;
	// if (argc == 2)
	// {
	// 	fd = open(argv[1], O_RDONLY);
	// 	if (fd < 0)
	// 	{
	// 		perror("Error");
	// 		exit(0);
	// 	}
	// 	reading_file(fd);
	// }
	// else if (argc == 3)
	// {
	// 	fd = open(argv[2], O_RDONLY);
	// 	if (fd < 0)
	// 	{
	// 		perror("Error");
	// 		exit(0);
	// 	}
	// 	reading_file(fd);
	// }
	// else
	// {
	// 	ft_printf("usage: ./asm file.s\n");
	// }


	//Lexical error at [5:9]
	
	printf("=========================\n");
	live_func(&func, 1, "live %");			//Syntax error at token [TOKEN][005:001] ENDLINE
	
	printf("=========================\n");
	live_func(&func, 1, "live ;1");			//Syntax error at token [TOKEN][005:001] ENDLINE
	
	printf("=========================\n");
	live_func(&func, 1, "			live");	//Syntax error at token [TOKEN][005:008] ENDLINE
	
	printf("=========================\n");
	live_func(&func, 1, "live %1adwawd");	//Syntax error at token [TOKEN][005:011] INSTRUCTION "adwawd"
	
	printf("=========================\n");
	live_func(&func, 1, "live %1 ''dawd");	//Lexical error at [5:9]
	
	printf("=========================\n");
	live_func(&func, 1, "live 1");			//Invalid parameter 0 type register for instruction live
	
	printf("=========================\n");
	live_func(&func, 1, "live r1"); 		//Invalid parameter 0 type register for instruction live

	printf("=========================\n");
	live_func(&func, 1, "live %1");

	return (0);
}