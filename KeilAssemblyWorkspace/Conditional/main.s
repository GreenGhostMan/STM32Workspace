			AREA findMaxNumber, CODE, READONLY
			ENTRY
			EXPORT __main
__main
			mov r1, #5
			mov r2, #8
			cmp r1, r2
			blt r1_small
			mov r0, r1
			B	Stop
r1_small
			mov r0, r2
			B 	Stop
Stop
			B 	Stop
			