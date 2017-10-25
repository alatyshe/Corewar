#------ make ------
all:
	@make -C libft/
	@make -C assembler/
	@make -C vm/
	@make -C decompiler/
	@make -C jvisualisation/

#------ make clean ------

clean: cleanlib
	@make clean -C libft/
	@make clean -C assembler/
	@make clean -C vm/
	@make clean -C decompiler/
	@make clean -C jvisualisation/

#------ make fclean ------
fclean:
	@make fclean -C libft/
	@make fclean -C assembler/
	@make fclean -C vm/
	@make fclean -C decompiler/
	@make fclean -C jvisualisation/

#------ make re ------
re: fclean all
