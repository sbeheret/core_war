.name           "42"
.comment        "Just a basic Winner Program"

entree:	live	%42		# entree
ld	%65535,r5
ld	%0,r5
zjmp	%:entree
ld %:entree, r10
add r4, r5, r4
live %1
ldi %15, r2, r1
