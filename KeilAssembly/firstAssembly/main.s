					AREA theCode, CODE, READONLY
					ENTRY
					EXPORT __main
__main
					LDR R0, =P
					MOV R1,#1
					STR R1, [R0]
					
					LDR R0, =S
					MOV R1, #5
					STR R1, [R0]
					
					LDR R0, =A
					MOV R1, #7
					STR R1, [R0]
					
Stop				B	Stop
					
					AREA	theData, DATA, READWRITE
P					SPACE	4
S					SPACE	4
A					SPACE 	4
					END