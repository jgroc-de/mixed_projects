.name "ld"
.comment "I'M ALIIIIVE"

lds:
test2:	ld %0, r1
	ld %193, r2
test1:	ld %666, r3
	ld %66666, r4
	ld %666666666, r5
	ld %-193, r2
test4:	ld %-666, r3
	ld %-66666, r4
	ld %-666666666, r5
	ld %:lds2, r10
	ld %:lds, r11
	ld %:test2, r12
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:test1, r13
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %:lds, r11
	ld %65400, r14
test3:	ld 193, r1
	ld 666, r2
	ld 66666, r3
	ld -213, r4
	ld -666, r5
	ld -66666, r6
	ld 1, r7
test5:	ld :lds, r8
	ld :test1, r9
	ld :lds2, r10
	fork %512
lds2: live %1 
