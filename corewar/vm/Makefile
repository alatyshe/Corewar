#----- Colors -----
BLACK ="\033[1;30m"
RED ="\033[1;31m"
GREEN ="\033[1;32m"
YELLOW = "\x1b[33m"
BLUE = "\x1b[34m"
MAGENTA = "\x1b[35m"
CYAN ="\033[1;35m"
PURPLE ="\033[1;36m"
WHITE ="\033[1;37m"
EOC ="\033[0;0m"
RESET = "\x1b[0m"
#==================

LIBRARY = ../libft/libft.a

NAME = ../corewar
HEAD = header/vm.h header/op.h

FLAGS = -Wall -Wextra -Werror


#------ path -------
FILES_PATH		= ./files
OTHER_PATH		= ./files/other
PRINT_PATH		= ./files/print
READ_PATH		= ./files/read
CMDS_PATH		= ./files/commands
MEM_MAP_PATH	= ./files/memory_map
VIS_PATH        = ./files/visual
OBJECTS_PATH	= ./objects


#------ files ------
FILES_FILES		= main
MEM_MAP_FILES	= memory_map fill_map kill_processes run_players
READ_FILES		= read_arguments read_header read_file read_flags
OTHER_FILES		= struct_create other
VISUAL_FILES    = visual func cont func2
PRINT_FILES		= print print_debug print_v_flag print_s_flag print_java_flag
CMDS_FILES		= fill_command fill_variables cmd_live cmd_ld cmd_st cmd_add cmd_sub\
				  cmd_and cmd_or cmd_xor cmd_zjmp cmd_ldi cmd_sti cmd_fork cmd_lld\
				  cmd_lldi cmd_lfork cmd_aff

#------ other ------
FILES_OBJ 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FILES_FILES)))
READ_OBJ		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(READ_FILES)))
CMDS_OBJ		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(CMDS_FILES)))
MEM_MAP_OBJ		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(MEM_MAP_FILES)))
OTHER_OBG 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(OTHER_FILES)))
VISUAL_OBJ      = $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(VISUAL_FILES)))
PRINT_OBJ		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(PRINT_FILES)))

#------ make ------
all: $(NAME)

$(NAME): $(FILES_OBJ) $(OTHER_OBG) $(READ_OBJ) $(CMDS_OBJ) $(MEM_MAP_OBJ) $(PRINT_OBJ) $(VISUAL_OBJ)
	@echo "\n"
	@make -C ../libft/
	@echo $(CYAN) "\tCompiling $@"$(RESET)
	@gcc $(FLAGS) -o $@ $^ -lncurses $(LIBRARY)
	@echo $(GREEN) "\tcorewar\t\t- has been made\n"$(RESET)

$(OBJECTS_PATH)/%.o: $(PRINT_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(FILES_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(OTHER_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(READ_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(CMDS_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(MEM_MAP_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(VIS_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<


#------ make clean ------
cleanlib:
	@make clean -C ../libft

clean: cleanlib
	@echo $(YELLOW)"\t\t\t\tCOREWAR"$(RESET)
	@rm -f $(FILES_OBJ)
	@rm -f $(OTHER_OBG)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)

#------ make fclean ------
fcleanlib:
	@make fclean -C ../libft

fclean: fcleanlib
	@echo $(YELLOW)"\t\t\t\tCOREWAR"$(RESET)
	@rm -f $(FILES_OBJ)
	@rm -f $(OTHER_OBG)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tcorewar have been cleaned.\n"$(RESET)

#------ make re ------
re: fclean all

