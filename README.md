# COREWAR

## What is Corewar?
* Corewar is a very peculiar game. It’s about bringing “players” together around a “virtual machine”, which will load some “champions” who will fight against one another with the support of “processes”, with the objective being for these champions to stay “alive”.

* The processes are executed sequentially within the same virtual machine and memory space. They can therefore, among other things, write and rewrite on top of each others so to corrupt one another, force the others to execute instructions that can damage them, try to rewrite on the go the coding equivalent of a Côtes du Rhône 1982 (that is one delicious French wine!), etc...

* The game ends when all the processes are dead. The winner is the last player reported to be “alive”.

## This Project Contain:
* **The assembler:** this is the program that will compile your champions and translate them from the language you will write them in (assembly language) into “Bytecode”.Bytecode is a machine code, which will be directly interpreted by the virtual machine.
* **Decompiler:** this is the program that will decompile champions and translate them from the “Bytecode” into assembly language.
* **The virtual machine:** It’s the “arena” in which your champions will be executed. It offers various functions, all of which will be useful for the battle of the champions. Obviously, the virtual machine should allow for numerous simultaneous processes; we are asking you for a gladiator fight, not a one-man show simulator.
* **Visualiser on JAVA:** implementation of an excellent visualizer on Java.
* **The champion:** This one is a special case. Later, in the championship, you will need to render a super powerful champion, who will scare the staff team to death. However, rendering this kind of champion is serious work. And since, for now, we are mostly interested in your capacity to create Corewar’s other programs (i.e. the assembler and virtual machine), your current champion will only need to prove to us that you can write bits and pieces of Corewar ASM. This means that the champion you should render for this project only needs to scare the bejesus out of a neurasthenic hedgehog.

### Installation

```sh
$ git clone https://github.com/alatyshe/Corewar.git corewar
$ cd corewar/corewar
$ make
```
Thats all. Project has been compiled.

## Using and run:
1. You must compile your champion(champions) by using **asm** programm.
2. Load bynary(*.cor) file(files) into **corewar**.

#### Asm:
Usage:
```sh
$ ./asm
usage: ./asm file.s
```
Compile:
```sh
$ ./asm ../champs/jumper.s ../champs/toto.s
Writing output program from ../champs/jumper.s to ../champs/jumper.cor
Writing output program from ../champs/toto.s to ../champs/toto.cor
```

#### Decompiler:
Decompile:
```sh
$ ./dcmp ../champs/toto.cor ../champs/jumper.cor
Writing output program to ../champs/dcmp_toto.s
Writing output program to ../champs/dcmp_jumper.s
```

#### Corewar:
Usage:
```sh
$ ./corewar
-a        : Prints output from "aff" (Default is to hide it)
#### TEXT OUTPUT MODE ##########################################################
-d N      : Dumps memory after N cycles then exits
-s N      : Runs N cycles, dumps memory, pauses, then repeats
-v N      : Verbosity levels, can be added together to enable several
	- 0 : Show only essentials
	- 1 : Show lives
	- 2 : Show cycles
	- 4 : Show operations (Params are NOT litteral ...)
	- 8 : Show deaths
	- 16 : Show PC movements (Except for jumps)
-db       : debugging output mode
#### NCURSES OUTPUT MODE #######################################################
-n        : Ncurses output mode
#### JAVA VISUALIZER OUTPUT MODE ###############################################
-java     : Java visualizer output mode
################################################################################
```
Start war:
```sh
$ ./corewar -n ../champs/jumper.cor ../champs/toto.cor
* Player 1, weighing 327 bytes, "|__beng__beng__beng__|" ("ozh.. ozhov.. ozhovuv!") !
* Player 2, weighing 325 bytes, "Celebration Funebre v0.99pl42" ("Jour J") !
Contestant 2, "Celebration Funebre v0.99pl42", has won !
```

#### Java visualisation:
* **Space** - pause/run
* **-** and **+** - speed control
* **C** - piano on/off
* **D** - music on/off

```sh
$ ./corewar -java ../champs/jumper.cor ../champs/toto.cor | java -jar jvisualiser.jar
```
