/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# define RED				"\x1b[31m"
# define GREEN				"\x1b[32m"
# define YELLOW				"\x1b[33m"
# define BLUE				"\x1b[34m"
# define MAGENTA			"\x1b[35m"
# define CYAN				"\x1b[36m"
# define BLACK				"\x1b[37m"
# define RESET				"\x1b[0m"

# define SAME				0

# define SYNTAX_ERROR		1
# define LEXICAL_ERROR		2
# define INVALID_INSTR		3
# define INVALID_PAR		4
# define NO_LABEL			5

# define LBL_INSTR			1
# define END				2
# define STRING_AFTER		3
# define ENDLINE			4
# define DIRECT				5
# define DIRECT_LABEL		6		
# define INSTRUCTION		7
# define REGISTER			8
# define INDIRECT			9
# define EMPTY				10
# define COUNT				11
# define TO_MANY_ARGS		12
# define COMMAND_NAME		13
# define COMMAND_COMMENT	14

# include <stdlib.h>
# include <stdio.h>

# include "op.h"
# include "asm.h"

# include "../../libft/header/libft.h"
# include "../../libft/header/ft_printf.h"

typedef struct		s_cmd
{
	char				*label;
	int					line;
	int					x;
	char				*str;
	short				cmd_size;
	char				cmd_in_hex;
	unsigned char		arg_types;
	union u_arg			**arg;
	struct s_cmd		*next;
}					t_cmd;

typedef union		u_arg
{
	int					num;
	short				shrt;
	unsigned char		chr;
}					t_arg;

typedef struct		s_header
{
	char				*file_name;
	unsigned int		magic;
	char				*prog_name;
	unsigned int		prog_size;
	char				*prog_comment;
	
	char				error;
	char				*error_str;

	int					last_cmd_line;
	int					line;

	int					x;
	t_cmd				*commands;
}					t_header;

t_cmd				*create_t_cmd();
t_arg				*create_t_arg();
t_header			*create_t_header();




int					find_chars_in_str(char *str, char *find);
int					cmp_char_with_str(char c, char *find);
int					check_new_line_at_the_end(int fd, int *x);
void				concat_and_free(char **cmt_cmd, char *read);
t_cmd				*get_last_cmd(t_header *head);
int					ft_str_find_char(char *str, int (*f)(int));
void				print_commands(t_header *head);
void				print_command(t_cmd *cmd);


int					fill_cmd_arg(t_header *head, t_cmd *cmd,
	char *str, int arg_num);
void				fill_command_arguments(t_header *head);

int					error_type(t_header *head, int type, int error);
int					error_line_char(t_header *head, char *str);

int					header(t_header *head, char *read, int fd);
void				label_command(t_header *head, char *read, int fd);

void				label(t_header *head, t_cmd *command,
	char *read, int fd);
void				command(t_header *head, t_cmd *cmd, char *read);

int					crop_name_comment(t_header *head);

int					check_symbols_after_cmd(t_header *head, t_cmd *cmd, char *read);
int					check_syntax(t_header *head, char *read, char *str);
int					check_number(t_header *head, char *read);


int					error_command(t_header *head, int type, int error);
int					error_label(t_header *head, int type, int error);
int					error_arguments(t_cmd *cmd, int type, int argc, char *type_arg);

int					create_file(t_header *header);

#endif
