/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2013/11/06 14:21:46 by zaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

# define CHAR_BIT	8
# define CHAR_MIN	–128
# define CHAR_MAX	127
# define UCHAR_MAX	255
# define SHRT_MIN	–32768
# define SHRT_MAX	32767
# define USHRT_MAX	65535
# define INT_MIN	–2147483648
# define INT_MAX	2147483647
# define UINT_MAX	4294967295
# define _I64_MIN	-9223372036854775808
# define _I64_MAX	9223372036854775807
# define _UI64_MAX	18446744073709551615

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE


# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

typedef char	t_arg_type;

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**
*/
//	chars(bytes)
# define PROG_NAME_LENGTH		(128)
//	chars(bytes)
# define COMMENT_LENGTH			(2048)
//	magic in header
# define COREWAR_EXEC_MAGIC		0xea83f3


typedef struct		header_s
{
  unsigned int		magic;	//	4 bytes == 32 bits == 0x00000000 (8 zeroes) in hex
  char				prog_name[PROG_NAME_LENGTH + 1]; // 128 + 1byte == 256(zeroes) + 2(zeroes) in hex
  unsigned int		prog_size; // 4 bytes == 32 bits == 0x00000000 (8 zeroes) in hex
  char				comment[COMMENT_LENGTH + 1]; // 2048 + 1 byte = 4096(zeroes) + 2(zeroes) in hex
}					header_t;
