P	EQU	4
S	EQU	5
A 	EQU	6
				AREA equ_test, CODE, READONLY
				ENTRY
				EXPORT __main
__main
				MOV R1, #P
				MOV R2, #S
				MOV R3, #A
				
				ADD R0, R1, R2
				ADD R0, R0, R3
				
				END