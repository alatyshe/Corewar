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

# include <stdio.h>
# include <stdlib.h>
# include <ncurses.h>

# include "../header/op.h"
# include "../../libft/header/libft.h"
# include "../../libft/header/ft_printf.h"




typedef struct		s_map
{
	char				map[MEM_SIZE];
	unsigned int		cycle;			//	текущий цикл
	unsigned int		cycle_to_die;	//	цикл смерти
	unsigned int		cycle_delta;
	unsigned int		processes;		//	количество процессов
	struct s_player		*players;		//	игроки
	// struct s_ps			*ps;
}					t_map;

typedef struct		s_ps
{
	int					pc;			//	позиция процесса на карте
	int					reg[16];	//	его регистры
	// int					color;
	char				cmd_in_hex;
	char				codage_byte;
	int					*arg;
	char				player;		//	номер игрока 1 2 4 8
	char				carry;		//	возможен ли перенос
	int					cycles_to_cmd;	//	текущее количесвто циклов до выполнения комманды
	int					check_live;		//	исполнил ли процесс функцию live
	int					p_size;			//	длинна исполняемой команды при исполнении
	struct s_ps			*next;
}					t_ps;

typedef struct		s_player
{
	char				*name;			//	имя игрока
	int					player_num;		//	номер игрока
	// int				color;			//	цвет
	unsigned int		last_live;		//	последний крик live (номер цикла)
	unsigned int		total_lives;	//	количество криков live
	struct s_ps			*ps;
	struct s_player		*next;
}					t_player;







typedef struct		s_cmd
{
	char				*cmd_name;
	short				cmd_size;
	char				cmd_in_hex;
	char				codage_byte;
	char				*arg_types;
	int					*arg;
	struct s_cmd		*next;
}					t_cmd;

typedef struct		s_info
{
	char				*file_name;
	unsigned int		magic;
	char 				*prog_name;
	unsigned int 		prog_size;
	char 				*prog_comment;
	
	int					player_num;
	unsigned char		*read;
	t_cmd				*commands;
	struct	s_info		*next;
}					t_info;


// ===================== read ========================

unsigned int	magic_reading(unsigned char *buf, t_info *info);
char			*name_reading(unsigned char *buf, t_info *info);
unsigned int	size_reading(unsigned char *buf, t_info *info);
char			*comment_reading(unsigned char *buf, t_info *info);
int				read_commands(unsigned char *buf, t_cmd *cmd, int pos_buf, int len_file);
t_info			*read_arguments(int argc, char **argv, int *counter_players);

void			read_file(char *file, t_info *info, int player_num);
// ===================== create struct ========================

t_info			*create_info(void);
t_cmd			*create_cmd(int	args);
t_map			*create_map(void);
t_player		*create_player(void);


void			move_pc(t_ps *ps, int delta_pos);
int				exec_arg_value(char *map, t_ps *ps, int len);
unsigned int 	get_value(void *buf, int len);
void			analyzing_buf(void *buf, int buf_size, t_info *info, char *file);
void			fill_map(t_info *info, t_map *map, int total_players);

void			print_buf(unsigned char *buffer, int buffer_size);
void			print_info(t_info *info);
void			print_cmd(t_cmd *cmd);
void			return_color(int n);
// void			print_map(short *map);
// void			print_wb_map(short *map);
void			print_players(t_player *player);
void			print_map(t_map *map);


//============================FUNC===============================
void			live(t_map *all_info, t_player *player, t_ps *ps);
void			ld(t_map *all_info, t_player *player, t_ps *ps);
#endif