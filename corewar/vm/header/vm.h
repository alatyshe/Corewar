/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvynokur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:49:51 by dvynokur          #+#    #+#             */
/*   Updated: 2017/10/25 17:06:39 by coleksii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# define RED		"\x1b[31m"
# define GREEN		"\x1b[32m"
# define YELLOW		"\x1b[33m"
# define BLUE		"\x1b[34m"
# define MAGENTA	"\x1b[35m"
# define CYAN		"\x1b[36m"
# define BLACK		"\x1b[37m"
# define RESET		"\x1b[0m"
# define BOLD_ON	"\x1b[1m"
# define BOLD_OFF	"\x1b[22m"

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
	char				a_flag;
	char				d_flag;
	int					d_value;
	char				n_flag;
	char				v_flag;
	int					v_value;
	char				s_flag;
	int					s_value;
	char				java_flag;
	char				db_flag;
}					t_flags;

typedef struct		s_map
{
	char				map[MEM_SIZE];
	unsigned int		cycle;
	int					cycle_to_die;
	unsigned int		total_lives;
	unsigned int		processes;
	unsigned int		ps_counter;
	char				checks;
	char				*winner;
	int					winner_num;
	struct s_player		*players;
	t_flags				*flags;
	struct s_ps			*ps;
	char				*clr;
	int					speed;
	int					speed_v;
}					t_map;

typedef struct		s_ps
{
	int					pc;
	int					player_num;
	int					*reg;
	char				cmd_in_hex;
	char				coding_byte;
	int					*arg_types;
	int					*arg;
	int					p_size;
	int					skip_cmd;
	int					cycles_to_cmd;
	int					cycles;
	char				carry;
	int					check_live;
	unsigned int		ps_num;
	struct s_ps			*next;
}					t_ps;

typedef struct		s_player
{
	char				*name;
	int					player_num;
	unsigned int		last_live;
	unsigned int		total_lives;
	struct s_player		*next;
}					t_player;

typedef struct		s_file
{
	char				*file_name;
	unsigned int		magic;
	char				*prog_name;
	unsigned int		prog_size;
	char				*prog_comment;
	int					player_num;
	unsigned char		*read;
	struct s_file		*next;
}					t_file;

typedef int			(*t_cmd_array)(t_map *all_info, t_ps *ps);

/*
** ===================== read ========================
*/

int					read_header(unsigned char *buf,
		t_file *file, char *file_name);
t_file				*read_prog_argv(int argc, char **argv,
		int *counter_players, t_flags *f);
int					check_flags(t_flags *f, char c, int n);
void				read_file(char *file_name, t_file *file, int player_num);
int					check_flags(t_flags *f, char c, int n);
void				num_arg_analysing(char *s, t_flags *f);
int					it_is_flag(char *s);
int					filling_flags(char *s, t_flags *flags);
void				min_arg_value(t_flags *f);

/*
** ================== memmory_map ======================
*/

void				memory_map(t_file *file, int total_players, t_flags *f);
void				fill_map(t_file *file, t_map *map, int total_players);
void				kill_processes(t_map *map);
void				run_players(t_map *map);

/*
** ================= create struct =====================
*/
t_file				*create_file(void);
t_map				*create_map(void);
t_player			*create_player(void);
t_ps				*create_ps(int pc, int player, int num);
t_flags				*create_flags(void);

/*
** =====================================================
*/
void				copy_process(t_ps *ps, t_ps *ps_new);
void				move_map_counter(int *pos, int delta_pos);
unsigned int		get_value_from_file(void *buf, int len);
int					get_value_from_map(t_map *all_info, int *where, int len);
void				write_value_on_map(t_map *map, int where,
		int value_in, t_ps *ps);
void				null_commands_variables(t_ps *ps);
int					exec_arg_value(char *map, t_ps *ps, int len);
unsigned int		get_value(void *buf, int len);
void				fill_map(t_file *file, t_map *map, int total_players);
void				print_players(t_player *player, t_map *map);
void				print_process(t_ps *ps);
void				print_processes(t_ps *ps);
void				print_file(t_file *file);
void				print_buf(unsigned char *buffer, int buffer_size);
void				print_v_flag_adv(t_map *map, t_ps *ps, int pc);
void				print_usage(void);
void				introducing_print(t_file *file);
void				print_flags(t_flags *f);
void				print_map_s_flag(t_map *map);
void				print_map_java(t_map *map, t_file *file);

/*
** ==================== commands ==========================
*/
int					fill_commands(t_map *all_info, t_ps *ps);
void				null_commands_variables(t_ps *ps);
int					get_variables_idxmod(t_map *all_info, t_ps *ps, int i);
int					get_variables(t_map *all_info, t_ps *ps, int i);
int					cmd_live(t_map *map, t_ps *ps);
int					cmd_ld(t_map *map, t_ps *ps);
int					cmd_st(t_map *map, t_ps *ps);
int					cmd_add(t_map *map, t_ps *ps);
int					cmd_sub(t_map *map, t_ps *ps);
int					cmd_and(t_map *map, t_ps *ps);
int					cmd_or(t_map *map, t_ps *ps);
int					cmd_xor(t_map *map, t_ps *ps);
int					cmd_zjmp(t_map *map, t_ps *ps);
int					cmd_ldi(t_map *map, t_ps *ps);
int					cmd_sti(t_map *map, t_ps *ps);
int					cmd_fork(t_map *map, t_ps *ps);
int					cmd_lld(t_map *map, t_ps *ps);
int					cmd_lldi(t_map *map, t_ps *ps);
int					cmd_lfork(t_map *map, t_ps *ps);
int					cmd_aff(t_map *map, t_ps *ps);
/*
** ==================== visual ===========================
*/

int					visual(t_map *m, int pl, t_file *file);
int					cursor_on_map(int num, int player, char *mem, char *clr);
int					cursor_from_map(int num, char *mem, char *clr);
int					put_on_map(int num, int player, char *mem, char *clr);
int					cycle(t_map *map);
int					cycle_to_die(int cycles);
int					ref(t_map *map);
void				winner(char *s);
int					position(int num, int *x, int *y);
int					create_skelet(int col, int row);
int					color_proc(char *clr, t_file *file, int players);
void				key_map(t_map *map);

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
