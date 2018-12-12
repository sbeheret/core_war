.name "OpCode"
.comment "All Functions"

live %1
ld %2, r1
st r1, r2
add r1, r2, r3
sub r1, r2, r3
and r1, r2, r3
or r1, r2, r3
xor r1, r2, r3
zjmp %1
ldi r1, r2, r3
sti r1, r2, r3
fork %1
lld 4, r1
lldi r1, r2, r3
lfork %1
aff r1
