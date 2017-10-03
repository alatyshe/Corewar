
#include "../header/asm.h"

void				print_command(t_cmd *cmd)
{
	printf("%s===================================%s\n", GREEN, RESET);
	printf("cmd->label\t: |%s|\n", cmd->label);
	printf("NAME\t\t: %s\n", g_tab[cmd->code - 1].name);
	printf("cmd->str\t: |%s|\n", cmd->str);
	printf("cmd->line\t: %d\n", cmd->line);
	printf("cmd->x\t\t: %d\n", cmd->x);
	printf("%s++++++++++++++++++++++++++++++++++++%s\n", MAGENTA, RESET);
	printf("cmd->cmd_size :\t|%d|\n", cmd->size);
	printf("\n");
	printf("%02x", cmd->code);
	if (g_tab[cmd->code - 1].coding_byte == 1)
		printf("%x", cmd->arg_types);
	printf("|%02x|", cmd->arg[0]->num);
	if (g_tab[cmd->code - 1].count_arg > 1)
		printf("|%02x|", cmd->arg[1]->num);
	if (g_tab[cmd->code - 1].count_arg > 2)
		printf("|%02x|", cmd->arg[2]->num);
	printf("\n%s===================================%s\n\n", RED, RESET);
}

void				print_commands(t_header *head)
{
	t_cmd			*cmd;

	cmd = head->commands;
	printf("head->prog_size : %x\n", head->prog_size);
	if (cmd)
		while (cmd->next)
		{
			print_command(cmd);
			cmd = cmd->next;
		}
}
