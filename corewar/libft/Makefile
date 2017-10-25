# ----- Colors -----
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
# ==================

NAME 	= libft.a
HEAD 	= header/libft.h header/ft_printf.h

FLAGS 	= -Wall -Wextra -Werror


#------ path -------
LFT_CHAR_PATH		= ./files/char
LFT_INT_PATH		= ./files/int
LFT_LST_PATH		= ./files/lst
LFT_OTHER_PATH		= ./files/other
LFT_STRING_PATH		= ./files/string

LFT_OBJECTS_PATH 	= ./objects


PF_SRC_PATH 		= ./files/printf/src
PF_PRINT_PATH 		= ./files/printf/print
PF_OBJECTS_PATH 	= ./files/printf/objects


#------ files ------
LFT_CHAR_FILES		= ft_isalnum ft_isalpha ft_isascii ft_isblank ft_isdigit ft_isnumber ft_isprint ft_isupper\
		ft_putchar ft_putchar_fd ft_tolower ft_toupper

LFT_INT_FILES		= ft_atoi ft_itoa ft_putnbr ft_putnbr_fd

LFT_LST_FILES		= ft_lst_size ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew

LFT_OTHER_FILES		= ft_bzero ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memmove\
		ft_memset get_next_line

LFT_STRING_FILES	= ft_putstr ft_strchr ft_strcpy ft_strequ ft_strjoin ft_strmap ft_strncmp ft_strnequ ft_strrchr\
		ft_strsub isdigit_str  ft_putstr_fd ft_strclr ft_strdel ft_striter ft_strlcat ft_strmapi ft_strncpy\
		ft_strnew ft_strsplit ft_strtrim skip_spaces  ft_strcat ft_strcmp ft_strdup ft_striteri ft_strlen\
		ft_strncat ft_strndup ft_strnstr ft_strstr isalpha_str skip_spaces_before_after_str skip_spaces


PF_SRC 				= ft_check_flags ft_for_decimal ft_for_lists ft_for_octals\
		ft_for_string ft_lst_modify ft_printf libft
PF_PRINT 			= ft_b ft_c_big ft_c ft_d ft_o ft_p ft_percent ft_print_flags\
		ft_s_big ft_s ft_u ft_x ft_xb


#------ other ------

LFT_CHAR_OBJ		= $(addprefix $(LFT_OBJECTS_PATH)/, $(addsuffix .o, $(LFT_CHAR_FILES)))
LFT_INT_OBJ			= $(addprefix $(LFT_OBJECTS_PATH)/, $(addsuffix .o, $(LFT_INT_FILES)))
LFT_LST_OBJ			= $(addprefix $(LFT_OBJECTS_PATH)/, $(addsuffix .o, $(LFT_LST_FILES)))
LFT_OTHER_OBJ		= $(addprefix $(LFT_OBJECTS_PATH)/, $(addsuffix .o, $(LFT_OTHER_FILES)))
LFT_STRING_OBJ		= $(addprefix $(LFT_OBJECTS_PATH)/, $(addsuffix .o, $(LFT_STRING_FILES)))	

PF_SRC_OBJ			= $(addprefix $(PF_OBJECTS_PATH)/, $(addsuffix .o, $(PF_SRC)))
PF_PRINT_OBJ		= $(addprefix $(PF_OBJECTS_PATH)/, $(addsuffix .o, $(PF_PRINT)))

#------ make ------
all: $(NAME)

$(NAME): $(LFT_CHAR_OBJ) $(LFT_INT_OBJ) $(LFT_LST_OBJ) $(LFT_OTHER_OBJ) $(LFT_STRING_OBJ) $(PF_SRC_OBJ) $(PF_PRINT_OBJ)
	@echo $(CYAN) "\n\tCompiling $@"$(RESET)
	@ar rc $(NAME) $(LFT_CHAR_OBJ) $(LFT_INT_OBJ) $(LFT_LST_OBJ) $(LFT_OTHER_OBJ) $(LFT_STRING_OBJ) $(PF_SRC_OBJ) $(PF_PRINT_OBJ)
	@ranlib $(NAME)
	@echo $(GREEN) "\tlibft.a\t\t- has been made\n"$(RESET)

$(LFT_OBJECTS_PATH)/%.o: $(LFT_CHAR_PATH)/%.c
	@mkdir $(LFT_OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(LFT_OBJECTS_PATH)/%.o: $(LFT_INT_PATH)/%.c
	@mkdir $(LFT_OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(LFT_OBJECTS_PATH)/%.o: $(LFT_LST_PATH)/%.c
	@mkdir $(LFT_OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(LFT_OBJECTS_PATH)/%.o: $(LFT_OTHER_PATH)/%.c
	@mkdir $(LFT_OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(LFT_OBJECTS_PATH)/%.o: $(LFT_STRING_PATH)/%.c
	@mkdir $(LFT_OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(PF_OBJECTS_PATH)/%.o: $(PF_SRC_PATH)/%.c
	@mkdir $(PF_OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(PF_OBJECTS_PATH)/%.o: $(PF_PRINT_PATH)/%.c
	@mkdir $(PF_OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -f $(LFT_SRC_OBJ)
	@rm -f $(PF_SRC_OBJ)
	@rm -f $(PF_PRINT_OBJ)
	@rm -rf $(LFT_OBJECTS_PATH)
	@rm -rf $(PF_OBJECTS_PATH)

fclean:
	@rm -f $(LFT_SRC_OBJ)
	@rm -f $(PF_SRC_OBJ)
	@rm -f $(PF_PRINT_OBJ)
	@rm -rf $(LFT_OBJECTS_PATH)
	@rm -rf $(PF_OBJECTS_PATH)
	@rm -f $(NAME)

re: fclean all
