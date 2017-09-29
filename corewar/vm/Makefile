VM_NAME = corewar

LIBRARY = ../libft/libft.a

VM_C = vm create_struct print_file read_file memory_map

VM_DIR = src/

OBJ_VM = $(addprefix $(VM_DIR),$(addsuffix .o,$(VM_C)))


# FLAGS = -Wall -Wextra -Werror

all: lib vm

lib:
	@make -C ../libft/

vm: $(OBJ_VM)
	@gcc -o $(VM_NAME) $(FLAGS) $(OBJ_VM) $(LIBRARY) 
	@echo "\x1b[32m"virtual machine has been made "\x1b[0m"

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $< 

clean:
	@find . -name "*.o" -type f -delete
	@echo "\x1b[31m".o files were deleted "\x1b[0m"

fclean: clean
	@rm -f $(VM_NAME) $(LIBRARY)
	@echo "\x1b[31m"exec files were deleted "\x1b[0m"

re: fclean all
