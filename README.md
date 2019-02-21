# Core War

---

As descrine in wikipedia [Core War](https://en.wikipedia.org/wiki/Core_War) is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language called Redcode

Our game in action
![Alt Text](https://github.com/rfibigr/core_war/divers/core_war_trim.gif)

This project contain two

## ASM

It will allow you to write programs destined to fight. It
will need to understand the assembly language, and generate binary programs
that can be interpreted by the virtual machine.


## Virtual Machine

It will house the binary programs (the champions)
and provide them with a standard execution environment. It offers a lot of
features useful to the fight. It goes without saying that it has to be able to
run multiple programs simultaneously (or the fights will be really, really dull
...)

## Technical details of the project

operation
cycle
lives

## My implementation

vm


## Executing Core War

command line

Usage
```bash
Usage: ./corewar [-dump N | -v N | -visu | -hex ]][[-n N]] <champion1.cor>] <...>

    -n N      : Change player number in ram
#### TEXT OUTPUT MODE#################################
    -dump N   : Dumps memory after N cycles then exits
    -p        : Print processus state (use with -dump)
    -v N      : Can be add together to enable multiple
          	 - 1 : Show lives
          	 - 2 : Show cycles
          	 - 4 : Show operations
          	 - 8 : Show deaths
          	 -16 : Show PC movements
#### CHAMPION OUTPUT MODE ############################
    -hex      : Hexdump champion before starting
#### NCURSES OUTPUT MODE #############################
    -visu     : Ncurses output mode
######################################################
```

to create player follow the documentation
and compile with the asm


## Author
