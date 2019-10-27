.name "zork2000"
.comment "zork from an ancient futur"

init0:
		sti r1, %:live0, %2
		st r16, -7
		st r16, -11
live0:
		ld %57339, r15
dragon0:
		live %-1
		fork %:shield0
		ld %57674497, r11
		ld %-1, r6
		fork %:dragon2
dragon1:
		ld %218750621, r10
		ld %-346, r13
		add r16, r16, r16
		st r10, 56870
		zjmp %56860
dragon2:
		ld %190056972, r10
		ld %-350, r13
		add r16, r16, r16
		st r10, 56839
		zjmp %56834
shield0:
		ld -10, r5
		fork %:shield1
shield1:
shield2:
		ld 656, r2
		ld 16842752, r3
		sub r5, r6, r5
		fork %:shield3
		add r16, r16, r16
		zjmp %:shield2
shield3:
		live %-3
		st r4, 56841
		st r2, 56840
		st r1, 56839
		st r3, 56838
		st r4, 56871
		st r2, 56870
		st r1, 56869
		st r3, 56868
		st r4, 56994
		st r2, 56993
		st r1, 56992
		st r3, 56991
		and r16, r16, r16
		zjmp %:shield3
setlive0:
		live %-3
