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

#endif