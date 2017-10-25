# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 19:41:05 by vboiko            #+#    #+#              #
#    Updated: 2017/10/25 20:37:28 by vboiko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
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

JFILES = Main.java CoreFrame.java enums/FieldSize.java MySounds.java \
			ui/MyColors.java MyFonts.java ui/Sound.java

CLASSFILES = CoreFrame\$$1.class CoreFrame\$$GameField.class MySounds.class \
				CoreFrame\$$PlacePoint.class CoreFrame\$$Player.class \
				CoreFrame.class Main.class enums/FieldSize.class \
				ui/MyColors.class MyFonts.class ui/Sound.class resources \

MANIFEST = MANIFEST.MF

JARNAME = ../jvisualiser.jar

DELFILES = CoreFrame\$$1.class CoreFrame\$$GameField.class MySounds.class \
				CoreFrame\$$PlacePoint.class CoreFrame\$$Player.class \
				CoreFrame.class Main.class enums/FieldSize.class \
				ui/MyColors.class MyFonts.class ui/Sound.class \
				ui/Sound\$$1.class ui/Sound\$$Listener.class \

all: build

build:
	@echo $(CYAN) "\tCompiling ../jvisualiser.jar"$(RESET)
	@ javac $(JFILES)
	@ jar mcf $(MANIFEST) $(JARNAME) $(CLASSFILES) ui
	@ echo $(GREEN)"\tJava visualiser compiled"$(RESET)

re: fclean build

clean:
	@echo $(YELLOW)"\t\t\t\tJAVA VISUALISER"$(RESET)
	@ rm -f $(DELFILES)
	@ echo $(RED)"\t.class files deleted"$(RESET)

fclean :
	@echo $(YELLOW)"\t\t\t\tJAVA VISUALISER"$(RESET)
	@ rm -f $(JARNAME)
	@ rm -f $(DELFILES)
	@ echo $(RED)"\tJava visualiser executable deleted"$(RESET)
