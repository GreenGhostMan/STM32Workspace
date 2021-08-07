VAR1 		RN	R0
VAR2		RN	R1
SUM			RN  R2

			AREA	rename_register, CODE,READONLY
			ENTRY
			EXPORT __main
__main
			MOV VAR1,#0X25
			MOV VAR2,#0X33
			ADD SUM, VAR1, VAR2
			
Stop		B	Stop
			END