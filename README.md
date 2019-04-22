# Corewar

Wikipedia: [Core War](https://en.wikipedia.org/wiki/Core_War) is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language called Redcode


Our game in action

![Alt Text](https://github.com/rfibigr/core_war/blob/master/divers/core_war_trim.gif?raw=true)

The project is divied in 2 parts :
+ [The assembler](#specification-of-the-champion-and-assembler) (asm) : It takes in parameter a champion written in Redcode and generate a binary program that can be interpreted by the virtual machine. Made by [ejsouza](https://github.com/ejsouza) and [dishults](https://github.com/dishults).
+ [The virtual machine](#details-of-the-project) (corewar) : Loads the binary programs (champions) and provide them with a standard execution environment. It offers a lot of features useful to the fight. Made by [me](https://github.com/sbeheret) and [rfibigr](https://github.com/rfibigr).

Champions are processes that will be loaded in the arena, represented by a virtual Ram, where they fight by executing a list of instructions in the VM.

## How to run the game

To install :

```bash
git clone https://github.com/rfibigr/core_war.git
cd core_war
make
```

Usage to generate Byte-code Champion
```bash
Usage: ./asm <champion.s>
```

Usage of the VM
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
If you use the viusalizer, for a best result, you should put your terminal in full screen.

Visualizer commands :
+ 'q' to quit
+ 'space' to start / pause
+ 'Up key' to increase the speed of execution
+ 'Down key' to decrease the speed of execution


Fight exemple :
```bash
./corewar -visu lockers_room/pai_mu_tan.cor lockers_room/TheHarvester.cor lockers_room/katchup.cor lockers_room/tchupka.cor
```

## Details of the project

Here's a [complete guide](https://docs.google.com/document/d/1DT_47inyTLDEUMevdmsA4jqr3_FXGvgKhzpGv_rtuOo/edit) to fully understand the project.

### Specifications of the vm

+ The arena has a total of MEM_SIZE (4096) bytes of memory and the memory is circular. When displayed, each bytes are in Hexadecimal on a 64 * 64 grid.
+ Maximum 4 players are loaded into the memmory as independant processes.
+ Each process has 16 registers of 4 bytes (r1 to r16) at disposition, along with a Program Counter (PC) which stores the next opcode address that will be executed.
+ The Virtual Machine can interpret and run [these 16 instructions](#champions-instructions) (from Opcode 0x01 to 0x10).
+ The VM has both a verbose mode and a visualizer to help debugging and to follow execution.

A "cycle" is over when we checked on all the processes (to simulate same-time, parallel, execution).

Each intruction takes a certain number of cycles to be executed.

The most important instruction, in this combat to death, is the instruction live (0x01). Live takes in parameter a champion number, writen on 4 bytes. The winner is the last champion that will be called alive.

Every 1536 (CYCLE_TO_DIE) cycles, the VM checks all the running processes. Each one that didn't call the instruction live are killed.
If after 21 (NBR_LIVE) calls to the instruction live, all proccesses are still alive then decrease the value of CYCLE_TO_DIE by 50 (CYCLE_DELTA).

The game ends when no champion are said to be alive during a CYCLE_TO_DIE cycles or if CYCLE_TO_DIE equals 0.

### Specification of the Champion and Assembler

Champions, written in Redcode, has 3 sections :
+ The name : starts with .name and size_max : 128 bytes
+ The comment: starts with .comment and size_max : 2048 bytes
+ The list of instrucitons (one by line)

example of a simple Champion :

```bash
cat champion/gilets_jaunes.s

.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
```

when we convert it into bytecode
```bash
./asm champion/gilets_jaunes.s && hexdump champion/gilets_jaunes.cor

00000000  00 ea 83 f3 7a 6f 72 6b  00 00 00 00 00 00 00 00  |....zork........|
00000010  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00000080  00 00 00 00 00 00 00 00  00 00 00 17 49 27 4d 20  |............I\'M |
00000090  41 4c 49 49 49 49 56 45  00 00 00 00 00 00 00 00  |ALIIIIVE........|
000000a0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
00000890  0b 68 01 00 0f 00 01 06  64 01 00 00 00 00 01 01  |.h......d.......|
000008a0  00 00 00 01 09 ff fb                              |.......|
000008a7
```

The champion are converted in byte-code with the following structure:
+ Magic number on 4 bytes  => 00 ea 83 f3
+ Name of the champion on 128 bytes => 7a 6f 72 6b
+ Padding of 4 bytes set to 0x00
+ Size of the Champion instructions part on 4 bytes => 00 00 00 17
+ Comment of the champion on 2048 bytes => 49 27 4d 20 41 4c 49 49 49 49 56 45
+ Padding of 4 bytes set to 0x00
+ Champion instructions => 0b 68 01 00 0f 00 01 06  64 01 00 00 00 00 01 01 00 00 00 01 09 ff fb

The instructions are converted to hexadecimal code.
The first byte is the Opcode of the instruction,
the second byte (if needed by the instruciton) is the encoding byte that determine the number of parameter, their types (register / direct / indirect ) and their size in the memory (1, 2 or 4 bytes)

on the precedent exemple

|opcode |	encoding byte | parameters | parameters | parameters |
|-------|-----------------|------------|-----------|------------|
| 0b (sti) 	| 68			|	01 (r1)		| 00 0f (address) | 00 01 |
| 06 (and)	| 64			|	01 (r1)		| 00 00 00 00 	| 01 |
| 01 (live)	| -				| 00 00 00 01 |					|		|
| 09 (zjump)| -				| ff fb			|				|		|



### Champion's instructions


| instruction  | Description |
|--------------|-------------|
|live | The argument taken is the player number, this instruction tells the vm that the player is alive. |
|ld | ́ld ́ stands for  ́Load ́, this instruction load the value from first parameter to the second parameter. (address is % IND_MOD)|
|st | ́st ́ stands for  ́store ́, this instruction saves the first parameter to a memory address or a registr. |
|add |Additions the values of first 2 registers then stores the result in 3rd parameter|
|sub |Subtracts the values of first 2 registers then stores the result in 3rd parameter |
|and |As add but does a bitwise  ́and ́ operation  ́a \& b ́. |
|or | As add but does a bitwise inclusive  ́or ́ operation  ́a \| b ́.|
|xor |As add but does a bitwise exclusive  ́or ́ operation  ́a \| b ́.|
|zjmp | The process jumps to a region of memory, if the carry flag is set to 1. The memory location is indicated in the argument. |
|ldi | The first two parameters are numbers, that are be added together and the result of the sum will be considered as a memory address from where the value will be loaded to the third parameter.(address is % IND_MOD)|
|sti | Here the manipulation are similar to ́ ldi ́, this instruction takes 3 parameter, and the last 2 are values that will be summed up and be considered as a memory address where the value of our first argument (register) will be saved. |
|fork |This instruction takes an address as parameter. The job of this instruction is to create a new process that will start from the index given as parameter. The new process is a copy of the parent process, exept for its address and its count of live instructions. (address is % IND_MOD)|
|lld |The  ́lld ́ stands for  ́long-load ́, it works same as  ́ld ́ with the only difference of not using  ́% IND_MOD ́ |
|lldi | Same as  ́ldi ́ but we do not use  ́% IND_MOD ́ |
|lfork | lfork is similar to the fork instruction but we do not use  ́% IND_MOD ́ |
|aff | This instruction takes a register as its only parameter writes the value of the register to the standard output.|




## Project partner

ejsouza : https://github.com/ejsouza

dishults : https://github.com/dishults

sbeheret : https://github.com/sbeheret

rfibigr : https://github.com/rfibigr
