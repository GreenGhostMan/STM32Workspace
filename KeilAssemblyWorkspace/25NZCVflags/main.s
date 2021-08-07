				AREA myCode, CODE, READONLY
				ENTRY
				EXPORT __main
__main
				MOV R2,#5
				MOV R3,#3
				MOV R4,#5
				
				SUBS R5,R2,R3
				SUBS R5,R2,R4
				
Stop			B	Stop
				END
					