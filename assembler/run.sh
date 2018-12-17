#!/bin/sh
RED='\033[0;4;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

for i in {1..3}
do
	echo $i
	../asm zork.s
	sleep .1
	rm -f zork.corprintf "${RED}21.s${NC}\n"
done
printf "\n${GREEN}*****************************************************************************************${NC}\n"
printf "${RED}21.s${NC}\n"
../asm ./tests/21.s
printf "${RED}42.s${NC}\n"
../asm ./tests/42.s
printf "${RED}one.s${NC}\n"
../asm ./tests/one.s
printf "${RED}tirb.s${NC}\n"
../asm ./tests/tirb.s
printf "${RED}zork.s${NC}\n"
../asm ./tests/zork.s
printf "${RED}Explosive_Kitty.s${NC}\n"
../asm ./tests/Explosive_Kitty.s
printf "${RED}Backwards.s${NC}\n"
../asm ./tests/Backward.s
printf "${RED}Car.s${NC}\n"
../asm ./tests/Car.s
printf "${RED}Death.s${NC}\n"
../asm ./tests/Death.s
printf "${RED}Gagnant.s${NC}\n"
../asm ./tests/Gagnant.s
printf "${RED}Octobre_Rouge_v4.2.s${NC}\n"
../asm ./tests/Octobre_Rouge_V4.2.s
printf "${RED}Survivor.s${NC}\n"
../asm ./tests/Survivor.s
printf "${RED}Torpille.s${NC}\n"
../asm ./tests/Torpille.s
printf "${RED}barriere.s${NC}\n"
../asm ./tests/barriere.s
printf "${RED}ex.s${NC}\n"
../asm ./tests/ex.s
printf "${RED}jumper.s${NC}\n"
../asm ./tests/jumper.s
printf "${RED}lde.s${NC}\n"
../asm ./tests/lde.s
printf "${RED}leeloo.s${NC}\n"
../asm ./tests/leeloo.s
printf "${RED}mat.s${NC}\n"
../asm ./tests/mat.s
printf "${RED}maxidef.s${NC}\n"
../asm ./tests//maxidef.s
printf "${RED}mortel.s${NC}\n"
../asm ./tests/mortel.s
printf "${RED}new.s${NC}\n"
../asm ./tests/new.s
printf "${RED}sebc.s${NC}\n"
../asm ./tests/sebc.s
printf "${RED}slider2.s${NC}\n"
../asm ./tests/slider2.s
printf "${RED}tdc2.s${NC}\n"
../asm ./tests/tdc2.s
printf "${RED}tdc3.s${NC}\n"
../asm ./tests/tdc3.s
printf "${RED}tdc4.s${NC}\n"
../asm ./tests/tdc4.s
printf "${RED}toto.s${NC}\n"
../asm ./tests/toto.s
printf "${RED}bee_gees.s${NC}\n"
../asm ./tests/bee_gees.s
printf "${RED}bigzork.s${NC}\n"
../asm ./tests/bigzork.s
printf "${RED}fluttershy.s${NC}\n"
../asm ./tests/fluttershy.s
printf "${RED}helltrain.s${NC}\n"
../asm ./tests/helltrain.s
printf "${RED}turtle.s${NC}\n"
../asm ./tests/turtle.s
printf "\n${GREEN}*****************************************************************************************${NC}\n"
printf "${CYAN}                                   Championships 2014${NC}\n"
printf "${GREEN}*****************************************************************************************${NC}\n"
printf "${RED}sam_2.0.s${NC}\n"
../asm ./tests/2014/sam_2.0.s
printf "${RED}doge.s${NC}\n"
../asm ./tests/2014/doge.s
printf "${RED}Rainbow_dash.s${NC}\n"
../asm ./tests/2014/Rainbow_dash.s
printf "${RED}youforkmytralala.s${NC}\n"
../asm ./tests/2014/youforkmytralala.s
printf "${RED}big_feet.s${NC}\n"
../asm ./tests/2014/big_feet.s
printf "${RED}loose.s${NC}\n"
../asm ./tests/2014/loose.s
printf "${RED}mandrogore.s${NC}\n"
../asm ./tests/2014/mandragore.s
printf "${RED}gedeon.s${NC}\n"
../asm ./tests/2014/gedeon.s
printf "${RED}terminator.s${NC}\n"
../asm ./tests/2014/terminator.s
printf "${RED}ultimate-surrender.s${NC}\n"
../asm ./tests/2014/ultimate-surrender.s
printf "${RED}_.s${NC}\n"
../asm ./tests/2014/_.s
printf "${RED}salamahenagalabadoun.s${NC}\n"
../asm ./tests/2014/salamahenagalabadoun.s
printf "${RED}Machine-gun.s${NC}\n"
../asm ./tests/2014/Machine-gun.s
printf "${RED}corelol.s${NC}\n"
../asm ./tests//2014/corelol.s
