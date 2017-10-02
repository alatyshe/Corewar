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
# include "../../libft/header/libft.h"
# include "../../libft/header/ft_printf.h"
# include <stdlib.h>

// typedef struct			s_info
// {
// 	unsigned int		magic;
// 	char				prog_name[PROG_NAME_LENGTH + 1];
// 	unsigned int		prog_size;
// 	char				commrnt[COMMENT_LENGTH + 1];

// }						t_info;



typedef struct			s_map
{
	short				map[MEM_SIZE + 1];
	unsigned int		cycle;
	unsigned int		cycle_to_die;
	unsigned int		cycle_delta;
	unsigned int		processes;
	struct s_player		*players;
	struct s_ps			*ps;
}						t_map;

typedef struct			s_ps
{
	t_map				*map;
	int					reg[16];
	char				player;
	char				carry;
	int					pc;
	int					pid;
	int					counter_cycles;
	int					p_size;
	struct s_ps			*next;
}						t_ps;

typedef struct			s_player
{
	char				*name;
	char				player;			//don't use it?
	int					player_num;
	unsigned int		last_live;
	unsigned int		lives;
	struct s_player		 *next;
}						t_player;









typedef struct		s_cmd
{
	char				*cmd_name;
	short				cmd_size;
	char				cmd_in_hex;
	char				codage_byte;
	char				*arg_types;
	union u_arg			**arg;
	struct s_cmd		*next;
}					t_cmd;

typedef union		u_arg
{
	int					num;
	short				shrt;
	unsigned char		chr;
}					t_arg;

typedef struct		s_info
{
	char				*file_name;
	unsigned int		magic;
	char 				*prog_name;
	unsigned int 		prog_size;
	char 				*prog_comment;
	
	char				error;

	t_cmd				*commands;
	struct	s_info		*next;
}					t_info;


// ===================== read ========================

unsigned int	magic_reading(void *buf, t_info *info);
char			*name_reading(void *buf, t_info *info);
unsigned int	size_reading(void *buf, t_info *info);
char			*comment_reading(void *buf, t_info *info);
t_cmd			*cmd_reading(void *buf, t_cmd *cmd, int pos_buf);


void			read_file(char *file, t_info *info);
// ===================== create struct ========================

t_info			*create_info(void);
t_cmd			*create_cmd(int	args);
t_map			*create_map(void);
t_player		*create_player(void);


unsigned int 	get_value(void *buf, int len);
void			analyzing_buf(void *buf, int buf_size, t_info *info, char *file);
void			print_cmd(t_cmd *cmd);
void			filling_map(t_info *info, t_player *player, int processes);

void			print_buf(void *buffer, int buffer_size);
void			print_info(t_info *info);

#endif