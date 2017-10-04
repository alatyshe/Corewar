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

#ifndef GIT_HEADER_H
#define GIT_HEADER_H

#include "asm.h"

int		create_file(t_header *header);
int 	write_program(int fd, t_header *header);
int 	write_arg(int fd, t_header *header, t_cmd *cmd);
int 	write_revers_bytes(int fd, int byte);
int		write_rev_short(int fd, short arg);

#endif
