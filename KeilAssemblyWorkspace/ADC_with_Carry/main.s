				AREA theCode, CODE, READONLY
				ENTRY
				EXPORT __main
__main
				LDR R0, =0XF62562FA
				LDR R1, =0XF412963B
				
				MOV R2, #0X35
				MOV R3, #0X21
				
				ADDS R5, R0, R1
				ADC  R6, R2, R3  ; R6 = 56 + c = 57
				
Stop			B Stop
				END