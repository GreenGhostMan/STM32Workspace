
			AREA Compact_Mode, CODE, READONLY
			ENTRY
			EXPORT __main
__main
			ADRL	R0, R
			LDR		R1, [R0,#4]
			LDR		R2, [R0,#8]
			LDR		R3, [R0,#12]
			
			ADD		R2, R1, R2
			ADD		R2, R2, R3
			
Stop		B	Stop
			AREA Compact_Mode, DATA, READONLY
R			SPACE   4
P			DCD		2
S			DCD		3
M			DCD		4
			ALIGN
			END