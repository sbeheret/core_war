.name "zork"
.comment "I'M ALIIIIVE"
#{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}
		ldi %:live, r1, r2
live:	live %1
