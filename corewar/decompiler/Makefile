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

NAME = ../dcmp
HEAD = header/dcmp.h header/op.h

FLAGS = -Wall -Wextra -Werror


#------ path -------
FILES_PATH		= ./files
OBJECTS_PATH	= ./objects


#------ files ------
FILES_FILES		= main create read_arguments read_commands read_file read_header writing

#------ other ------
FILES_OBJ 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FILES_FILES)))

#------ make ------
all: $(NAME)

$(NAME): $(FILES_OBJ)
	@echo "\n"
	@make -C ../libft/
	@echo $(CYAN) "\tCompiling $@"$(RESET)
	@gcc $(FLAGS) -o $@ $^ -lncurses $(LIBRARY)
	@echo $(GREEN) "\tdcmp\t\t- has been made(decompiler)\n"$(RESET)

$(OBJECTS_PATH)/%.o: $(FILES_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

#------ make clean ------
cleanlib:
	@make clean -C ../libft

clean: cleanlib
	@echo $(YELLOW)"\t\t\t\tDECOMPILER"$(RESET)
	@rm -f $(FILES_OBJ)
	@rm -f $(OTHER_OBG)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)

#------ make fclean ------
fcleanlib:
	@make fclean -C ../libft

fclean: fcleanlib
	@echo $(YELLOW)"\t\t\t\tDECOMPILER"$(RESET)
	@rm -f $(FILES_OBJ)
	@rm -f $(OTHER_OBG)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tdecompiler (dcmp) have been cleaned.\n"$(RESET)

#------ make re ------
re: fclean all


