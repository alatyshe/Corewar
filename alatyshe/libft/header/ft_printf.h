/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 17:48:08 by alatyshe          #+#    #+#             */
/*   Updated: 2017/01/27 17:48:09 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <locale.h>

typedef struct	s_pflist
{
	int			spc;
	int			hash;
	int			plus;
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			prec;
	int			length;
	char		decimalize;
}				t_pflist;

typedef void	(*t_pf_array)(t_pflist *lst, int *count, va_list ap);
int				ft_printf(const char *fmt, ...);
int				ft_lst_use(char *str, int *i, int *count, va_list ap);
int				ft_check_letter(t_pflist *lst, char *str, int i);
void			ft_use_letter(t_pflist *lst, int *count,
	char letter, va_list ap);
int				ft_size_bin(wchar_t a);
size_t			ft_strlen_big(wchar_t *s);
char			*ft_strdup(const char *s1);
int				ft_search_h(char *str, int *i);
int				ft_check_length(t_pflist *lst, char *str, int *i);
void			ft_func_star(t_pflist *lst, char *str, int *i, va_list ap);
int				ft_lst_fill(t_pflist *lst, char *str, int *i, va_list ap);
void			ft_lst_modify_x(t_pflist *lst, char *str);
void			ft_lst_modify_b(t_pflist *lst, char *str);
void			ft_lst_modify_o(t_pflist *lst, char *str);
int				ft_prnstr(char const *s, int length);
int				ft_printstr_big(wchar_t const *s, int length);
int				ft_sizeof_wchar(wchar_t s);
int				ft_char(int i, char b);
size_t			ft_get_unsigned_from_length(t_pflist *lst, va_list ap);
intmax_t		ft_get_signed_from_length(t_pflist *lst, va_list ap);
void			ft_fill_itoa(size_t value, size_t base, char *str, int *i);
char			*ft_itoa_base_p(size_t join, int sstm);
t_pflist		*ft_create_lst(void);
void			ft_lst_modify_d(t_pflist *lst, char *str);
void			ft_lst_modify_u(t_pflist *lst, char *str);
void			ft_lst_modify_s(t_pflist *lst, char *str);
void			ft_lst_modify_sb(t_pflist *lst, wchar_t *str);
void			ft_create_func_arr(t_pf_array *use_letter);
int				ft_check_for_atoi(char *str);
int				ft_atoi_plus(const char *str, int *c);
int				print_wchar_2(unsigned int v);
int				print_wchar_3(unsigned int v);
int				print_wchar_4(unsigned int v);
int				printing_char(wchar_t value);
void			ft_c_big(t_pflist *lst, int *count, va_list ap);
void			ft_c(t_pflist *lst, int *count, va_list ap);
void			ft_print_d(t_pflist *lst, int *count, char *str);
void			ft_print_one(t_pflist *lst, int *count, char *str);
void			ft_d(t_pflist *lst, int *count, va_list ap);
void			ft_func_for_zero(t_pflist *lst, int *count, int flag);
void			ft_print_o(t_pflist *lst, int *count, char *str);
void			ft_o(t_pflist *lst, int *count, va_list ap);
void			ft_func_for_zero2(t_pflist *lst, int *count, int flag);
void			ft_print_p(t_pflist *lst, int *count, char *str);
void			ft_p(t_pflist *lst, int *count, va_list ap);
void			ft_percent(t_pflist *lst, int *count);
void			ft_print_flags(t_pflist *lst, char *str, int *count, int *i);
void			ft_for_s_big(t_pflist *lst, wchar_t *str, int *count);
void			ft_s_big(t_pflist *lst, int *count, va_list ap);
void			ft_print_s(t_pflist *lst, int *count, char *str);
void			ft_s(t_pflist *lst, int *count, va_list ap);
void			ft_print_u(t_pflist *lst, int *count, char *str);
void			ft_print_two(t_pflist *lst, int *count, char *str);
void			ft_u(t_pflist *lst, int *count, va_list ap);
void			ft_print_x(t_pflist *lst, int *count, char *str);
void			ft_x(t_pflist *lst, int *count, va_list ap);
void			ft_print_xb(t_pflist *lst, int *count, char *str);
void			ft_xb(t_pflist *lst, int *count, va_list ap);
void			ft_uppercase(char **str);
void			ft_print_b(t_pflist *lst, int *count, char *str);
void			ft_b(t_pflist *lst, int *count, va_list ap);
#endif
