Core War

---

As describe in Wikipedia, [Core War](https://en.wikipedia.org/wiki/Core_War) is a 1984 programming game created by D. G. Jones and A. K. Dewdney in which two or more battle programs (called "warriors") compete for control of a virtual computer. These battle programs are written in an abstract assembly language called Redcode


Our game in action

![Alt Text](https://github.com/rfibigr/core_war/blob/master/divers/core_war_trim.gif?raw=true)

The project is divied in 3 parts :
+ The assembler (asm) : It will allow you to write programs destined to fight. It take in parameter a champion write in Redcode and generate a binary programs that can be interpreted by the virtual machine.
+ The virtual machine (corewar) : It will house the binary programs (the champions)and provide them with a standard execution environment. It offers a lot of features useful to the fight.
+ The champion is writen in semi assembly language Redcode.

Champion are processus that will be load in the arena represented by a virtual Ram where they fight by executing a list of instructions in the VM.

More detail in the following paragraph.

## Details of the project

#### Specifications of the vm

+ The virtual machine has a total of MEM_SIZE (4096) bytes of memory and the memory is circular.
+ The arena is the representation of the memory. Value of each byte is display in Hexadecimale in a 64*64 grid.
+ Maximum of 4 champions can be load in the memmory
+ Each processus contain 16 registers of 4 bytes (r1 - r16)
+ VM can execute 16 instructions listed below (from Opcode 0x01 to 0x10)

Our virtual CPU can exectue a [list of 16 instructions](#Champions-instructions). Each intructions taking a number of cycle to be executed. 16 registers of 4 bytes are in disposition to process the instruction.

One the most important instruction in this combat to death between the proccessus is the instruction live (0x01). Live take in parameter a champion name writen on 4 bytes. The winner is the last champion that will be called alive.

Every CYCLE_TO_DIE (1536), the VM check all the processus running. Every processus that didn't call the instruction live are killed. After every CYCLE_TO_DIE cycle, we also check if the number of instruction live is superior at NBR_LIVE(21). If it's the case the CYCLE_TO_DIE number is decrement by CYCLE_DELTA (50).

The game take end when no champion are call alive during a CYCLE_TO_DIE cycles or if CYCLE_TO_DIE is decrement to 0.

#### Specification of the Champion and Assembler

Champion is write in Redcode and comporte 3 sections :
+ The name : start with .name and size_max : 128 bytes
+ The comment: stat with .comment and size_max: 2048 bytes
+ The list of instrucitons (one by line)

example a simple Champion :

```bash
cat champion/gilets_jaunes.s

.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
```

when transform in bytecode
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

The instruction are transform to hexadecimal code.
the first byte represent the opcode of the instruction
the second bytes (if needed by the instruciton) is the encoding bytes that determine the number of parameter, their types (register / direct / indirect ) and theirs size on the memory (1, 2 or 4 bytes)

on the precedent exemple

|opcode |	encoding byte | parameters | parameters | parameters |
|-------|-----------------|------------|-----------|------------|
| 0b (sti) 	| 68			|	01 (r1)		| 00 0f (address) | 00 01 |
| 06 (and)	| 64			|	01 (r1)		| 00 00 00 00 	| 01 |
| 01 (live)	| -				| 00 00 00 01 |					|		|
| 09 (zjump)| -				| ff fb			|				|		|



#### Champion's instructions


| instruction  | Description |
|--------------|-------------|
|live | The argument taken is the player number, this instruction tells the vm that the player is alive. |
|ld | ́ld ́ stands for  ́Load ́, this instruction load the value from first parameter to the second parameter. (address is % IND_MOD)|
|st | ́st ́ stands for  ́store ́, this instruction saves the first parameter to a memory address or a registr. |
|add |This instruction is used to addition the values of first 2 registers then stores the result in 3rd parameter|
|sub |This one works same as add the only difference is that it subtracts the values of first 2 registers then stores the result in 3rd parameter |
|and |This op code is same as add but it does an bitwise  ́and ́ operation  ́a & b ́. |
|or | This op code is same as add but it does an bitwise inclusive  ́or ́ operation  ́a | b ́.|
|xor |This op code is same as add but it does an bitwise exclusive  ́or ́ operation  ́a | b ́.|
|zjmp | zjmp jumps to a certain region of memory if the carry flag is set to 1. The memory location is indicated in the argument. |
|ldi | This instruction takes 3 parameter where the first two parameters are numbers which is considered addresses, that will be added together (an addition) and then the result of the sum will be considered a memory address from where the value containing the address will be loaded to the third parameter.(address is % IND_MOD)|
|sti | Here the manipulation are similar to ́ ldi ́, this instruction takes 3 parameter, and the last 2 are values that will be summed up and be considered as a memory address where the value of our first argument (register) will be saved. |
|fork |This instruction takes an address as parameter. The job of this instruction is to create a new process that will start the process from the index given as parameter. The new process copy different stat of the parent process.The different stats include ALL the registers values but PC register because PC flag will be the parameter given to it and the count of live instruction called by the current process. (address is % IND_MOD)|
|lld |The  ́lld ́ stands for  ́long-load ́, it works same as  ́ld ́ the only difference is that we do not use  ́% IND_MOD ́ |
|lldi | Same as  ́ldi ́ but we do not use  ́% IND_MOD ́ |
|lfork | lfork is similar to the fork instruction but we do not use  ́% IND_MOD ́ |
|aff | This instruction takes a register as its only parameter writes the value of the register to the standard output.|


## My implementation

In this project I developp the Virtual Machine.

+ First we recupere the champion in byte-code and verify thate the file is a valid champion.
+ Then we create the environnement of the VM (processus and memory) and load the champion on it.
+ For every cycle we check if processus are finish their previous exection and exectute the next instruction.
+ To execute an instruction we decode the Opcode and the encoding-byte to extract the parameter and execute the instruction after waiting the number of cycle needed to be executed
+ After some cycle We update the CYCLE_TO_DIE and continu to execute the intructions until the game end.
+ Create a verbose mode to obtain information at every cycle.

## How to run the game

command line

Usage to generate Byte-code Champion
```bash
Usage: ./asm <champion.s>
```

Usage to execute the VM
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
If you use the viusalizer, you need to put your terminal in full screen for a best result.

Visualizer command :
+ 'q' to quit
+ 'space' to start pause
+ 'Up key' to increase the number of cycle each second
+ 'Down key' to reduce the number of cycle each second


Fight exemple :
```bash
./corewar -visu lockers_room/pai_mu_tan.cor lockers_room/TheHarvester.cor lockers_room/katchup.cor lockers_room/tchupka.cor
```


## Project partner

ejsouza : https://github.com/ejsouza
dishults : https://github.com/dishults
sbeheret : https://github.com/sbeheret
