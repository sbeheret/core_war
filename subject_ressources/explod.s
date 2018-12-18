.name "Explode"
.comment "Exploding"

start: ld -42, r2
		zjmp %:start
first_attack: sti r10, r15, r9
		live %42
