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


int						save_command(t_header *head, char **save_in, char *str, int fd)
{
	char				*pos;
	char				*find_error;

	if ((pos = ft_strchr(str, '"')) == NULL)
	{
		*save_in = ft_strjoin("", str);
		while (get_next_line(fd, &str))
		{
			if ((pos = ft_strchr(str, '"')) != NULL)
			{
				*pos++ = '\0';
				// дописать функцию для  проверки на мусор после скобки (.name "" dawwdawd)
				*save_in = ft_strjoin(*save_in, str);
				break ;
			}
			else
			{
				*save_in = ft_strjoin(*save_in, str);
				*save_in = ft_strjoin(*save_in, "\n");
			}
		}
	}
	else
	{
		*pos++ = '\0';
		// дописать функцию для  проверки на мусор после скобки (.name "" dawwdawd)
		*save_in = ft_strdup(str);
	}
	printf("|%s|\n", *save_in);
	return (1);
}

int						check_comment_name(t_header *head, char *str, int fd)
{
	int					x;

	x = skip_spaces(str); 
	if (str[x])
	{
		if (str[x] == '#')
			return (0);
		else if (str[x] == '.' && ft_strncmp(".name", str + x, 5) == SAME)
		{
			x = skip_spaces_before_after_cmd(str + x + 1) + 1;
			if (str[x] != '"')
 				return (error_message_type(LEXICAL_ERROR, head, x));
 			x++;
 			save_command(head, &head->prog_name, str + x, fd);
		}
		else if (str[x] == '.' && ft_strncmp(".comment", str + x, 7) == SAME)
		{
			x = skip_spaces_before_after_cmd(str + x + 1) + 1;
			if (str[x] != '"')
				return (error_message_type(LEXICAL_ERROR, head, x));
			x++;
			save_command(head, &head->prog_comment, str + x, fd);
		}
		else
			return (error_message_type(SYNTAX_ERROR, head, x));
	}
	return (0);
}


t_header				*reading_file(int fd)
{
	char				*str;
	t_header			*head;
	int 				y;
	int					x;
	int					i;
	

	head = create_t_header();
	y = 0;
	x = 0;
	while (get_next_line(fd, &str) > 0)
	{
		y++;
		if (head->prog_name == NULL || head->prog_comment == NULL)
			x = check_comment_name(head, str, fd);
		else if (head->prog_name != NULL && head->prog_comment != NULL)
			;// check_functions_labels( , str);


		if (head->error > 0)
			return (error_message_y_x(head, y, x, str));
		free(str);
		str = NULL;
	}
	if (str != NULL)
		printf("Error");
	return (head);
}

void				valid_name(t_header *head, char *str)
{

	printf("%s\n", str);	
}

int					main(int argc, char **argv)
{
	int				fd;
	t_function		func;
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
	{
		ft_printf("usage: ./asm file.s\n");
	}

	
	// printf("=========================\n");
	// live_func(&func, 1, "live %");			//Syntax error at token [TOKEN][006:001] ENDLINE
	
	// printf("=========================\n");
	// live_func(&func, 1, "live ;1");			//Syntax error at token [TOKEN][006:008] ENDLINE
	
	// printf("=========================\n");
	// live_func(&func, 1, "			live");	//Syntax error at token [TOKEN][005:008] ENDLINE
	
	// printf("=========================\n");
	// live_func(&func, 1, "live %1adwawd");	//Syntax error at token [TOKEN][005:011] INSTRUCTION "adwawd"
	
	// printf("=========================\n");
	// live_func(&func, 1, "live %1 ''dawd");	//Lexical error at [5:9]
	
	// printf("=========================\n");
	// live_func(&func, 1, "live 1");			//Invalid parameter 0 type register for instruction live
	
	// printf("=========================\n");
	// live_func(&func, 1, "live r1"); 		//Invalid parameter 0 type register for instruction live

	// printf("=========================\n");
	// live_func(&func, 1, "live %1");


	return (0);
}