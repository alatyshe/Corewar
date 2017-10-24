/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/08/20 16:49:52 by dvynokur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DCMP_H
# define DCMP_H
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define BLACK   "\x1b[37m"
# define RESET   "\x1b[0m"
# define FIRST_ARG		0
# define SECOND_ARG		1
# define THIRD_ARG		2
# include <stdio.h>
# include <stdlib.h>
# include <ncurses.h>
# include "../header/op.h"
# include "../../libft/header/libft.h"
# include "../../libft/header/ft_printf.h"

typedef struct			s_cmd
{
	char				*cmd_name;
	short				cmd_size;
	int					cmd_in_hex;
	char				coding_byte;
	char				arg_types[3];
	int					arg[3];
	struct s_cmd		*next;
}						t_cmd;
typedef struct			s_file
{
	char				*file_name;
	unsigned int		magic;
	char				*prog_name;
	unsigned int		prog_size;
	char				*prog_comment;
	int					player_num;
	unsigned char		*read;
	t_cmd				*commands;
	struct s_file		*next;
}						t_file;
t_file					*read_prog_argv(int argc, char **argv,
						int *counter_players);
t_file					*filling_files(t_file *start, int *counter_players,
						char *s);
int						read_header(unsigned char *buf, t_file *file,
						char *file_name);
t_cmd					*read_commands(unsigned char *buf, int pos_buf,
						int file_len);
int						fill_args(unsigned char *buf, t_cmd *cmd,
						int pos_buf, int argc);
void					read_file(char *file_name, t_file *file,
						int player_num);
t_file					*create_file(void);
t_cmd					*create_cmd();
unsigned int			get_value_from_file(void *buf, int len);
void					writing_to_file(t_file *file);
void					writing_commands(int fd, t_file *file);
void					writing_header(int fd, t_file *file);
char					*create_name_of_file(char *s);

#endif
