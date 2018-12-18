.name "Gilets Jaunes"
.comment "Qu'ils viennent me chercher"

ld 0, r4
ld %:jump, r3
ld %655357, r2 # 09 00 00 = 655357
st r2, %5

jump: live %1
