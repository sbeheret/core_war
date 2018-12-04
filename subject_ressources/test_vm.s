.name "zork"
.comment "I'M ALIIIIVE"

live %1000
ld -42, r2
ld %150, r3
ld %2093902, r4
ld 2093902, r5
st r1, -42
st r1, 20
st r1, 12938
st r1, r2

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %-6
