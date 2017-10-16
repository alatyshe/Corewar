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

# define FIRST_ARG		0
# define SECOND_ARG		1
# define THIRD_ARG		2

# include <stdio.h>
# include <stdlib.h>
# include <ncurses.h>

# include "../header/op.h"
# include "../../libft/header/libft.h"
# include "../../libft/header/ft_printf.h"

typedef struct		s_flags
{
	char			a_flag;
	char			b_flag;
	char			d_flag;
	int				d_value;
	char			j_flag;
	char			n_flag;
	char			v_flag;
	int				v_value;
	char			s_flag;
	int				s_value;
}					t_flags;


typedef struct		s_map
{
	char				map[MEM_SIZE];
	unsigned int		cycle;			//	текущий цикл
	unsigned int		cycle_to_die;	//	цикл смерти
	unsigned int		total_lives;
	unsigned int		processes;		//	количество процессов
	unsigned int		ps_counter;
	struct s_player		*players;		//	игроки
	t_flags				*flags;
	struct s_ps			*ps;
}					t_map;

typedef struct		s_cmd
{
	short				cmd_size;
	int					cmd_in_hex;
	char				coding_byte;
	char				arg_types[3];
	int					arg[3];
}					t_cmd;

typedef struct		s_ps
{
	int					pc;				//	позиция процесса на карте
	int					player_num;		//	номер игрока 1 2 4 8
	int					reg[16];		//	его регистры

	char				cmd_in_hex;		//	
	char				coding_byte;	//	
	int					*arg_types;		//	тип аргументов
	int					*arg;			//	сами аргументы
	int					p_size;			//	длинна исполняемой команды при исполнении

	int					skip_cmd;		//	пропуск команды на ошибочном кодирующем бите
	int					cycles_to_cmd;	//	текущее количесвто циклов до выполнения комманды

	char				carry;			//	возможен ли перенос 1 - 0
	int					check_live;		//	исполнил ли процесс функцию live
	unsigned int		ps_num;			//	номер процесса
	struct s_ps			*next;
}					t_ps;

typedef struct		s_player
{
	char				*name;			//	имя игрока
	int					player_num;		//	номер игрока
	// int				color;			//	цвет
	unsigned int		last_live;		//	последний крик live (номер цикла)
	unsigned int		total_lives;	//	количество криков live
	// struct s_ps			*ps;
	struct s_player		*next;
}					t_player;

typedef struct		s_file
{
	char				*file_name;
	unsigned int		magic;
	char 				*prog_name;
	unsigned int 		prog_size;
	char 				*prog_comment;
	int					player_num;
	unsigned char		*read;
	t_cmd				*commands;
	struct	s_file		*next;
}					t_file;

typedef void	(*t_cmd_array)(t_map *all_info, t_ps *ps);

// ===================== read ========================

unsigned int	magic_reading(unsigned char *buf, t_file *file);
char			*name_reading(unsigned char *buf);
unsigned int	size_reading(unsigned char *buf, char *file_name);
char			*comment_reading(unsigned char *buf);
int				read_commands(unsigned char *buf, t_cmd *cmd, int pos_buf, int len_file);
t_file			*read_arguments(int argc, char **argv, int *counter_players, t_flags *f);

void			read_file(char *file_name, t_file *file, int player_num);
void			memory_map(t_file *file, int total_players, t_flags *f);
// ===================== create struct ========================

t_file			*create_file(void);
t_cmd			*create_cmd();
t_map			*create_map(void);
t_player		*create_player(void);
t_ps			*create_ps(int pc, int player, int num);
t_flags			*create_flags(void);

void			move_map_counter(int *pos, int delta_pos);
unsigned int	get_value_from_file(void *buf, int len);
int				get_value_from_map(t_map *all_info, int *where, int len);
void			write_value_on_map(t_map *all_info, int where, int value_in);
void			null_commands_variables(t_ps *ps);
void			null_cmd(t_cmd *cmd);

int				exec_arg_value(char *map, t_ps *ps, int len);
unsigned int 	get_value(void *buf, int len);
void			fill_map(t_file *file, t_map *map, int total_players);


void			print_buf(unsigned char *buffer, int buffer_size);
void			print_file(t_file *file);
void			print_cmd(t_cmd *cmd);
void			return_color(int n);
// void			print_map(short *map);
// void			print_wb_map(short *map);
void			print_process(t_ps *ps);
void			print_processes(t_ps *ps);
void			print_players(t_player *player);
void			print_map(t_map *map);
void			print_flags(t_flags *f);
void			print_info_map(t_map *map);
void			introducing_print(t_file *file);
void			print_load_store(int pc, int new_pc, t_ps *ps, t_map *map);

int				it_is_flag(char *s);
int				check_flags(t_flags *f, char c, int n);

//============================FUNC===============================
int				fill_commands(t_map *all_info, t_ps *ps);
void			null_commands_variables(t_ps *ps);
int				get_variables_idxmod(t_map *all_info, t_ps *ps, int i, int types);
void			cmd_live(t_map *map, t_ps *ps);
void			cmd_ld(t_map *map, t_ps *ps);
void			cmd_st(t_map *map, t_ps *ps);
void			cmd_add(t_map *map, t_ps *ps);
void			cmd_sub(t_map *map, t_ps *ps);
void			cmd_and(t_map *map, t_ps *ps);
void			cmd_or(t_map *map, t_ps *ps);
void			cmd_xor(t_map *map, t_ps *ps);
void			cmd_zjmp(t_map *map, t_ps *ps);
void			cmd_ldi(t_map *map, t_ps *ps);
void			cmd_sti(t_map *map, t_ps *ps);
void			cmd_fork(t_map *map, t_ps *ps);
void			cmd_lld(t_map *map, t_ps *ps);
void			cmd_lldi(t_map *map, t_ps *ps);
void			cmd_lfork(t_map *map, t_ps *ps);
void			cmd_aff(t_map *map, t_ps *ps);


static t_cmd_array	g_cmd_arr[17] = {
	NULL,
	cmd_live,
	cmd_ld,
	cmd_st,
	cmd_add,
	cmd_sub,
	cmd_and,
	cmd_or,
	cmd_xor,
	cmd_zjmp,
	cmd_ldi,
	cmd_sti,
	cmd_fork,
	cmd_lld,
	cmd_lldi,
	cmd_lfork,
	cmd_aff
};

#endif