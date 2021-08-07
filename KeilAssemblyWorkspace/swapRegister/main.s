
						AREA theCode, CODE, READONLY
						ENTRY
						EXPORT __main
__main
						LDR R0, =0X123ABC
						LDR R1, =0X456DEF
						
						EOR R0, R0, R1
						EOR R1, R0, R1
						EOR R0, R0, R1
						
Stop					B Stop
						END
						
						