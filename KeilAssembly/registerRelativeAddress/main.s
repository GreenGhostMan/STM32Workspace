;Register Relative Addressing
; STR = STORE
; LDR = LOAD
; B = branch

R		EQU 	0
P		EQU		4
S		EQU		8
A		EQU		12
	
			AREA Register_relative_Code, CODE,READONLY
			ENTRY
			EXPORT __main
__main
			ADRL R4, values
			LDR		R1,[R4,#P]
			LDR		R2,[R4,#S]
			LDR		R3,[R4,#A]
			
			ADD		R0, R1, R2
			ADD		R0, R0, R3
			STR		R0, [R4,#R]
			
Stop		B	Stop
			
			
			AREA Register_relative_data, DATA, READONLY
			
values		SPACE	4
			DCD		3
			DCD		4
			DCD		5
				
			ALIGN
			END
				