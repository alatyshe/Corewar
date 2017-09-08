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



int						find_chars_in_str(char *str, char *find)
{
	int					i;
	int 				j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (find[j])
		{
			if (str[i] == find[j])
				return (i);
			j++;
		}
		i++;
	}
	return (-1);
}

int 					cmp_char_with_str(char c, char *find)
{
	int					i;

	i = 0;
	while (find[i])
	{
		if (find[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_exp					*create_t_exp()
{
	t_exp				*res;

	res = (t_exp*)malloc(sizeof(t_exp));
	res->at_the_start = 0;
	res->at_the_end = 0;
	res->next = NULL;
	return (res);
}

t_reg_exp				*create_t_reg_exp()
{
	t_reg_exp		*exp;

	exp = (t_reg_exp *)malloc(sizeof(t_reg_exp));
	exp->string = NULL;
	exp->expression = NULL;
	exp->next = NULL;
	return (exp);
}

void				print_regexp(t_reg_exp *lst)
{
	t_reg_exp 		*exp;

	exp = lst;

	while (exp)
	{
		printf("exp->type :   |%c|\n", exp->type);
		printf("exp->string : |%s|\n", exp->string);
		// printf("exp->expression : |%s|\n", exp->expression);
		printf("%s==============================================%s\n\n", GREEN, RESET);
		exp = exp->next;
	}
}

int						ft_regexp(char *string, char *reg_exp)
{
	int				i;
	int				len;
	t_reg_exp		*exp;
	t_reg_exp		*res;

	i = 0;
	len = ft_strlen(reg_exp);
	exp = create_t_reg_exp();
	res = exp;
	printf("%s|%s|%s\n\n", RED, reg_exp, RESET);
	while (reg_exp[i] && i < len)
	{
		if (reg_exp[i] != '[')
		{
			// запись всего регулярнго выражения
			exp->type = 's';
			exp->string = ft_strndup(reg_exp + i, find_chars_in_str(reg_exp + i, "[^$.*+?|( \t\n\v\r\f"));
			while (reg_exp[i] && !cmp_char_with_str(reg_exp[i], "[^$.*+?|( \t\n\v\r\f"))
				i++;
			// заполнение флагов если они есть
			if (cmp_char_with_str(reg_exp[i], "("))
				exp->flags = ft_strndup(reg_exp + i, find_chars_in_str(reg_exp + i, ")"));
			if (reg_exp[i + 1])
			{
				exp->next = create_t_reg_exp();
				exp = exp->next;
			}
		}
		if (reg_exp[i] == '[')
		{
			i++;
			// запись всего регулярнго выражения
			exp->type = '[';
			exp->string = ft_strndup(reg_exp + i, find_chars_in_str(reg_exp + i, "]"));
			while(reg_exp[i] && reg_exp[i] != ']')
				i++;
			// заполнение флагов если они есть
			if (cmp_char_with_str(reg_exp[i], "("))
				exp->flags = ft_strndup(reg_exp + i, find_chars_in_str(reg_exp + i, ")"));
			// если регулярное выражение не закончилось, то создаем новое
			if (reg_exp[i + 1])
			{
				exp->next = create_t_reg_exp();
				exp = exp->next;
			}
		}
		i++;
	}
	print_regexp(res);
	return (i);
}

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

	char str[] = "wow";
	ft_regexp(str, "      |AS    [awdaw] [1234make]");

	return (0);
}