/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alatyshe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:17:23 by alatyshe          #+#    #+#             */
/*   Updated: 2016/12/12 16:22:52 by alatyshe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# define SYNTAX_ERROR	1
# define LEXICAL_ERROR	2
# define INVALID_INSTR	3
# define INVALID_PAR	4

# include "asm.h"
# include "other.h"
# include "func.h"
# include "op.h"
# include "validation.h"

int					error_message_type(int type, t_header *head, int x);
void 				*error_message_y_x(t_header *head, int y, int x, char *str);

#endif



