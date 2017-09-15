/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

# include "asm.h"
# include "validation.h"
# include "other.h"
# include "func.h"
# include "op.h"

t_function			*create_t_function();
t_arg				*create_t_arg();
t_header			*create_t_header();

int					skip_spaces_before_after_cmd(char *str);
int					skip_numbers(char *str);
int					skip_spaces(char *str);
int					find_chars_in_str(char *str, char *find);
int 				cmp_char_with_str(char c, char *find);
int 				check_new_line_at_the_end(int fd, int *x);
void				concat_and_free(char **cmt_cmd, char *read);
t_function			*get_last_function(t_header *head);
int					ft_str_find_char(char *str, int (*f)(int));
void				print_functions(t_header *head);

#endif
