; Storing Constants on Memory
				AREA store_constant_data, DATA, READONLY
R				SPACE   4
Z				DCD	    1
W				DCD		3
M				DCD		4
	
				AREA store_constant, CODE, READONLY
				ENTRY
				EXPORT __main
					
__main
				LDR 	R1,Z
				LDR 	R2,W
				LDR		R3,M
				
				ADD R0, R1, R2
				ADD R0, R0, R3
				
Stop			B 	Stop
				END