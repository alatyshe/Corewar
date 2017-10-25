# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 19:41:05 by vboiko            #+#    #+#              #
#    Updated: 2017/10/25 15:26:05 by vboiko           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

JFILES = Main.java CoreFrame.java enums/FieldSize.java \
			ui/MyColors.java MyFonts.java ui/Sound.java

CLASSFILES = CoreFrame\$$1.class CoreFrame\$$GameField.class \
				CoreFrame\$$PlacePoint.class CoreFrame\$$Player.class \
				CoreFrame.class Main.class enums/FieldSize.class \
				ui/MyColors.class MyFonts.class ui/Sound.class resources \

MANIFEST = MANIFEST.MF

JARNAME = JVisualiser.jar

DELFILES = CoreFrame\$$1.class CoreFrame\$$GameField.class \
				CoreFrame\$$PlacePoint.class CoreFrame\$$Player.class \
				CoreFrame.class Main.class enums/FieldSize.class \
				ui/MyColors.class MyFonts.class ui/Sound.class \
				ui/Sound\$$1.class ui/Sound\$$Listener.class \

all: build

build:
	@javac $(JFILES)
	@jar mcf $(MANIFEST) $(JARNAME) $(CLASSFILES) ui
	@echo $(CYAN)"\tJava visualiser compiled"$(RESET)

re: fclean build

clean:
	@rm $(DELFILES)
	@echo $(RED)"\t.class files deleted"$(RESET)

fclean : clean
	@rm $(JARNAME)
	@echo $(RED)"\tJava visualiser executable deleted"$(RESET)
