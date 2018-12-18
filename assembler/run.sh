#!/bin/sh
RED='\033[0;4;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'
YELLOW='\033[0;4;33m'

function cmpcor() {
if diff -q "$1" "$2"
then
	printf "${GREEN}Your "$1" is equal to ZAZ "$2"${NC}\n"
else
	printf "${RED}Your "$1" is not equal to ZAZ "$2" or inaccessible${NC}\n"
fi
										}

										for i in {1..3}
										do
											echo $i
											../asm zork.s
											sleep .1
											rm -f zork.corprintf "${YELLOW}21.s${NC}\n"
										done
										printf "\n${GREEN}*****************************************************************************************${NC}\n"

										printf "${YELLOW}21.s${NC}\n"
										./asm ./tests/21.s
										cmpcor "./tests/21.s" "./tests/21.s"
										printf "${YELLOW}42.s${NC}\n"
										./asm ./tests/42.s
										printf "${YELLOW}one.s${NC}\n"
										./asm ./tests/one.s
										printf "${YELLOW}tirb.s${NC}\n"
										./asm ./tests/tirb.s
										printf "${YELLOW}zork.s${NC}\n"
										./asm ./tests/zork.s
										printf "${YELLOW}Explosive_Kitty.s${NC}\n"
										./asm ./tests/Explosive_Kitty.s
										printf "${YELLOW}Backwards.s${NC}\n"
										./asm ./tests/Backward.s
										printf "${YELLOW}Car.s${NC}\n"
										./asm ./tests/Car.s
										printf "${YELLOW}Death.s${NC}\n"
										./asm ./tests/Death.s
										printf "${YELLOW}Gagnant.s${NC}\n"
										./asm ./tests/Gagnant.s
										printf "${YELLOW}Octobre_Rouge_v4.2.s${NC}\n"
										./asm ./tests/Octobre_Rouge_V4.2.s
										printf "${YELLOW}Survivor.s${NC}\n"
										./asm ./tests/Survivor.s
										printf "${YELLOW}Torpille.s${NC}\n"
										./asm ./tests/Torpille.s
										printf "${YELLOW}barriere.s${NC}\n"
										./asm ./tests/barriere.s
										printf "${YELLOW}ex.s${NC}\n"
										./asm ./tests/ex.s
										printf "${YELLOW}jumper.s${NC}\n"
										./asm ./tests/jumper.s
										printf "${YELLOW}lde.s${NC}\n"
										./asm ./tests/lde.s
										printf "${YELLOW}leeloo.s${NC}\n"
										./asm ./tests/leeloo.s
										printf "${YELLOW}mat.s${NC}\n"
										./asm ./tests/mat.s
										printf "${YELLOW}maxidef.s${NC}\n"
										./asm ./tests//maxidef.s
										printf "${YELLOW}mortel.s${NC}\n"
										./asm ./tests/mortel.s
										printf "${YELLOW}new.s${NC}\n"
										./asm ./tests/new.s
										printf "${YELLOW}sebc.s${NC}\n"
										./asm ./tests/sebc.s
										printf "${YELLOW}slider2.s${NC}\n"
										./asm ./tests/slider2.s
										printf "${YELLOW}tdc2.s${NC}\n"
										./asm ./tests/tdc2.s
										printf "${YELLOW}tdc3.s${NC}\n"
										./asm ./tests/tdc3.s
										printf "${YELLOW}tdc4.s${NC}\n"
										./asm ./tests/tdc4.s
										printf "${YELLOW}toto.s${NC}\n"
										./asm ./tests/toto.s
										printf "${YELLOW}bee_gees.s${NC}\n"
										./asm ./tests/bee_gees.s
										printf "${YELLOW}bigzork.s${NC}\n"
										./asm ./tests/bigzork.s
										printf "${YELLOW}fluttershy.s${NC}\n"
										./asm ./tests/fluttershy.s
										printf "${YELLOW}helltrain.s${NC}\n"
										./asm ./tests/helltrain.s
										printf "${YELLOW}turtle.s${NC}\n"
										./asm ./tests/turtle.s
										printf "\n${GREEN}*****************************************************************************************${NC}\n"
										printf "${CYAN}                                   Championships 2014${NC}\n"
										printf "${GREEN}*****************************************************************************************${NC}\n"

										printf "${YELLOW}sam_2.0.s${NC}\n"
										./asm ./tests/2014/sam_2.0.s
										cmpcor "./tests/2014/sam_2.0.cor" "./tests/2014/zaz/zaz_sam_2.0.cor"
										printf "${YELLOW}doge.s${NC}\n"
										./asm ./tests/2014/doge.s
										cmpcor "./tests/2014/doge.cor" "./tests/2014/zaz/zaz_doge.cor"
										printf "${YELLOW}Rainbow_dash.s${NC}\n"
										./asm ./tests/2014/Rainbow_dash.s
										cmpcor "./tests/2014/Rainbow_dash.cor" "./tests/2014/zaz/zaz_Rainbow_dash.cor"
										printf "${YELLOW}youforkmytralala.s${NC}\n"
										./asm ./tests/2014/youforkmytralala.s
										cmpcor "./tests/2014/youforkmytralala.cor" "./tests/2014/zaz/zaz_youforkmytralala.cor"
										printf "${YELLOW}big_feet.s${NC}\n"
										./asm ./tests/2014/big_feet.s
										cmpcor "./tests/2014/big_feet.cor" "./tests/2014/zaz/zaz_big_feet.cor"
										printf "${YELLOW}loose.s${NC}\n"
										./asm ./tests/2014/loose.s
										cmpcor "./tests/2014/loose.cor" "./tests/2014/zaz/zaz_loose.cor"
										printf "${YELLOW}mandrogore.s${NC}\n"
										./asm ./tests/2014/mandragore.s
										cmpcor "./tests/2014/mandragore.cor" "./tests/2014/zaz/zaz_mandragore.cor"
										printf "${YELLOW}gedeon.s${NC}\n"
										./asm ./tests/2014/gedeon.s
										cmpcor "./tests/2014/gedeon.cor" "./tests/2014/zaz/zaz_gedeon.cor"
										printf "${YELLOW}terminator.s${NC}\n"
										./asm ./tests/2014/terminator.s
										cmpcor "./tests/2014/terminator.cor" "./tests/2014/zaz/zaz_terminator.cor"
										printf "${YELLOW}ultimate-surrender.s${NC}\n"
										./asm ./tests/2014/ultimate-surrender.s
										cmpcor "./tests/2014/ultimate-surrender.cor" "./tests/2014/zaz/zaz_ultimate-surrender.cor"
										printf "${YELLOW}_.s${NC}\n"
										./asm ./tests/2014/_.s
										cmpcor "./tests/2014/_.cor" "./tests/2014/zaz/zaz_.cor"
										printf "${YELLOW}salamahenagalabadoun.s${NC}\n"
										./asm ./tests/2014/salamahenagalabadoun.s
										cmpcor "./tests/2014/salamahenagalabadoun.cor" "./tests/2014/zaz/zaz_salamahenagalabadoun.cor"
										printf "${YELLOW}Machine-gun.s${NC}\n"
										./asm ./tests/2014/Machine-gun.s
										cmpcor "./tests/2014/Machine-gun.cor" "./tests/2014/zaz/zaz_Machine-gun.cor"
										printf "${YELLOW}corelol.s${NC}\n"
										./asm ./tests//2014/corelol.s
										cmpcor "./tests/2014/corelol.cor" "./tests/2014/zaz/zaz_corelol.cor"
										printf "${YELLOW}Asombra.s${NC}\n"
										./asm ./tests//2014/Asombra.s
										cmpcor "./tests/2014/Asombra.cor" "./tests/2014/zaz/zaz_Asombra.cor"
										printf "${YELLOW}Kappa.s${NC}\n"
										./asm ./tests//2014/Kappa.s
										cmpcor "./tests/2014/Kappa.cor" "./tests/2014/zaz/zaz_Kappa.cor"
										printf "${YELLOW}MarineKing.s${NC}\n"
										./asm ./tests//2014/MarineKing.s
										cmpcor "./tests/2014/Marineking.cor" "./tests/2014/zaz/zaz_Marineking.cor"
										printf "${YELLOW}Misaka_Mikoto.s${NC}\n"
										./asm ./tests//2014/Misaka_Mikoto.s
										cmpcor "./tests/2014/Misaka_Mikoto.cor" "./tests/2014/zaz/zaz_Misaka_Mikoto.cor"
										printf "${YELLOW}THUNDER.s${NC}\n"
										./asm ./tests//2014/THUNDER.s
										cmpcor "./tests/2014/THUNDER.cor" "./tests/2014/zaz/zaz_THUNDER.cor"
										printf "${YELLOW}Varimathras.s${NC}\n"
										./asm ./tests//2014/Varimathras.s
										cmpcor "./tests/2014/Varimathras.cor" "./tests/2014/zaz/zaz_Varimathras.cor"
										printf "${YELLOW}_honeybadger.s${NC}\n"
										./asm ./tests//2014/_honeybadger.s
										cmpcor "./tests/2014/_honeybadger.cor" "./tests/2014/zaz/zaz_honeybadger.cor"
										printf "${YELLOW}casimir.s${NC}\n"
										./asm ./tests//2014/casimir.s
										cmpcor "./tests/2014/casimir.cor" "./tests/2014/zaz/zaz_casimir.cor"
										printf "${YELLOW}champ.s${NC}\n"
										./asm ./tests//2014/champ.s
										cmpcor "./tests/2014/champ.cor" "./tests/2014/zaz/zaz_champ.cor"
										printf "${YELLOW}darksasuke.s${NC}\n"
										./asm ./tests//2014/darksasuke.s
										cmpcor "./tests/2014/darksasuke.cor" "./tests/2014/zaz/zaz_darksasuke.cor"
										printf "${YELLOW}dubo.s${NC}\n"
										./asm ./tests//2014/dubo.s
										cmpcor "./tests/2014/dubo.cor" "./tests/2014/zaz/zaz_dubo.cor"
										printf "${YELLOW}jinx.s${NC}\n"
										./asm ./tests//2014/jinx.s
										cmpcor "./tests/2014/jinx.cor" "./tests/2014/zaz/zaz_jinx.cor"
										printf "${YELLOW}justin_bee.s${NC}\n"
										./asm ./tests//2014/justin_bee.s
										cmpcor "./tests/2014/justin_bee.cor" "./tests/2014/zaz/zaz_justin_bee.cor"
										printf "${YELLOW}littlepuppy.s${NC}\n"
										./asm ./tests//2014/littlepuppy.s
										cmpcor "./tests/2014/littlepuppy.cor" "./tests/2014/zaz/zaz_littlepuppy.cor"
										printf "${YELLOW}live.s${NC}\n"
										./asm ./tests//2014/live.s
										cmpcor "./tests/2014/live.cor" "./tests/2014/zaz/zaz_live.cor"
										printf "${YELLOW}meowluigi.s${NC}\n"
										./asm ./tests//2014/meowluigi.s
										cmpcor "./tests/2014/meowluigi.cor" "./tests/2014/zaz/zaz_meowluigi.cor"
										printf "${YELLOW}skynet.s${NC}\n"
										./asm ./tests//2014/skynet.s
										cmpcor "./tests/2014/skynet.cor" "./tests/2014/zaz/zaz_skynet.cor"
										printf "${YELLOW}Douceur_power.s${NC}\n"
										./asm ./tests/2017/Douceur_power.s
										cmpcor "./tests/2017/Douceur_power.cor" "./tests/2017/zaz/zaz_Douceur_power.cor"
										printf "${YELLOW}Explosive_Kitty.s${NC}\n"
										./asm ./tests/2017/Explosive_Kitty.s
										cmpcor "./tests/2017/Explosive_Kitty.cor" "./tests/2017/zaz/zaz_Explosive_Kitty.cor"
										printf "${YELLOW}Kittystrophic.s${NC}\n"
										./asm ./tests/2017/Kittystrophic.s
										cmpcor "./tests/2017/Kittystrophic.cor" "./tests/2017/zaz/zaz_Kittystrophic.cor"
										printf "${YELLOW}gateau.s${NC}\n"
										./asm ./tests/2017/gateau.s
										cmpcor "./tests/2017/gateau.cor" "./tests/2017/zaz/zaz_gateau.cor"
										printf "${YELLOW}mise_a_jour_windows95.s${NC}\n"
										./asm ./tests//2017/mise_a_jour_windows95.s
										cmpcor "./tests/2017/mise_a_jour_windows95.cor" "./tests/2017/zaz/zaz_mise_a_jour_windows95.cor"
										printf "${YELLOW}overwatch.s${NC}\n"
										./asm ./tests/2017/overwatch.s
										cmpcor "./tests/2017/overwatch.cor" "./tests/2017/zaz/zaz_overwatch.cor"
										printf "${YELLOW}run_Kitty_RUN.s${NC}\n"
										./asm ./tests/2017/run_Kitty_RUN.s
										cmpcor "./tests/2017/run_Kitty_RUN.cor" "./tests/2017/zaz/zaz_run_Kitty_RUN.cor"
										printf "${YELLOW}ultima.s${NC}\n"
										./asm ./tests/2017/ultima.s
										cmpcor "./tests/2017/ultima.cor" "./tests/2017/zaz/zaz_ultima.cor"
