
				AREA hacker, CODE, READONLY
				ENTRY
				EXPORT __main
__main
				MOV R6, #0X1234
				MOV R3, #0X1234
				
				ADD R4, R6, R3
				
				
Stop			B Stop
				END