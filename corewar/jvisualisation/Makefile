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

BLUE = "\033[1;36m"
RESET = "\x1b[0m"

JFILES = Main.java CoreFrame.java enums/FieldSize.java \
			ui/MyColors.java MyFonts.java ui/Sound.java

CLASSFILES = CoreFrame\$$1.class CoreFrame\$$GameField.class \
				CoreFrame\$$PlacePoint.class CoreFrame\$$Player.class \
				CoreFrame.class Main.class enums/FieldSize.class \
				ui/MyColors.class MyFonts.class ui/Sound.class resources \

MANIFEST = MANIFEST.MF

JARNAME = jvisualiser.jar

DELFILES = CoreFrame\$$1.class CoreFrame\$$GameField.class \
				CoreFrame\$$PlacePoint.class CoreFrame\$$Player.class \
				CoreFrame.class Main.class enums/FieldSize.class \
				ui/MyColors.class MyFonts.class ui/Sound.class \
				ui/Sound\$$1.class ui/Sound\$$Listener.class \

all: build clean

build:
	@ javac $(JFILES)
	@ jar mcf $(MANIFEST) $(JARNAME) $(CLASSFILES) ui
	@ echo $(BLUE)"Java visualiser compiled"$(RESET)

re: build clean

clean:
	@ rm $(DELFILES)
	@ echo $(BLUE)".class files deleted"$(RESET)

fclean : clean
	@ rm $(JARNAME)
	@ echo $(BLUE)"Java visualiser executable deleted"$(RESET)