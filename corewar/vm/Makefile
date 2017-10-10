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

NAME = corewar
HEAD = header/vm.h header/op.h

# FLAGS = -Wall -Wextra -Werror


#------ path -------
FILES_PATH		= ./files
OTHER_PATH		= ./files/other
READ_PATH		= ./files/read
FUNC_PATH		= ./files/func
OBJECTS_PATH	= ./objects


#------ files ------
FILES_FILES		= main memory_map fill
READ_FILES		= read_arguments read_header read_commands read_file 
OTHER_FILES		= struct_create other print
FUNC_FILES		= fill_command live ld st add sub and or xor zjmp ldi

#------ other ------
FILES_OBJ 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FILES_FILES)))
READ_OBJ		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(READ_FILES)))
FUNC_OBJ		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FUNC_FILES)))
OTHER_OBG 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(OTHER_FILES)))


#------ make ------
all: $(NAME)

$(NAME): $(FILES_OBJ) $(OTHER_OBG) $(READ_OBJ) $(FUNC_OBJ)
	@echo "\n"
	@make -C ../libft/
	@echo $(CYAN) "\tCompiling $@"$(RESET)
	@gcc $(FLAGS) -o $@ $^ -lncurses $(LIBRARY)
	@echo $(GREEN) "\tcorewar\t\t- has been made\n"$(RESET)

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

$(OBJECTS_PATH)/%.o: $(FUNC_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

#------ make clean ------
cleanlib:
	# @make clean -C ../libft

clean: cleanlib
	@echo $(YELLOW)"\t\t\t\tCOREWAR"$(RESET)
	@rm -f $(FILES_OBJ)
	@rm -f $(OTHER_OBG)
	@echo $(RED) "\t.o files have been cleaned.\n"$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)

#------ make fclean ------
fcleanlib:
	# @make fclean -C ../libft

fclean: fcleanlib
	@echo $(YELLOW)"\t\t\t\tCOREWAR"$(RESET)
	@rm -f $(FILES_OBJ)
	@rm -f $(OTHER_OBG)
	@echo $(RED) "\t.o files have been cleaned.\n"$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tcorewar have been cleaned.\n"$(RESET)

#------ make re ------
re: fclean all


