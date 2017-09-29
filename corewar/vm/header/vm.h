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

#ifndef VM_H
# define VM_H
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define BLACK   "\x1b[37m"
# define RESET   "\x1b[0m"
# include "../header/op.h"
# include <stdio.h>
// # include "../libft/libft.h"
# include "../../alatyshe/libft/header/libft.h"
# include "../../alatyshe/libft/header/ft_printf.h"
# include <stdlib.h>

// typedef struct			s_info
// {
// 	unsigned int		magic;
// 	char				prog_name[PROG_NAME_LENGTH + 1];
// 	unsigned int		prog_size;
// 	char				commrnt[COMMENT_LENGTH + 1];

// }						t_info;
typedef struct		s_cmd
{
	char				*cmd_name;
	short				cmd_size;
	char				cmd_in_hex;
	char				codage_byte;

	char				*arg_types; // t_dir t_reg, t_ind
	union u_arg			**arg;
	struct s_cmd		*next;
}					t_cmd;

typedef union		u_arg
{
	int					num;
	short				shrt;
	unsigned char		chr;
}					t_arg;

typedef struct	s_info
{
	char				*file_name;
	unsigned int		magic;
	char 				*prog_name;
	unsigned int 		prog_size;
	char 				*prog_comment;
	
	char				error;

	t_cmd				*commands;
	struct	s_info		*next;
}						t_info;


unsigned int	magic_reading(void *buf, t_info *info);
char			*name_reading(void *buf, t_info *info);
unsigned int	size_reading(void *buf, t_info *info);
char			*comment_reading(void *buf, t_info *info);
void			reading(char *file, t_info *info);
void			print_buf(void *buffer, int buffer_size);
void			print_info(t_info *info);
t_info			*create_info(void);
t_cmd			*create_cmd(int	args);
unsigned int 	get_value(void *buf, int len);
void			analyzing_buf(void *buf, int buf_size, t_info *info, char *file);
void			print_cmd(t_cmd *cmd);

#endif