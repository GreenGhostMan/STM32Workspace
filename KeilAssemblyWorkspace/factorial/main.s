				AREA factorial, CODE, READONLY
				ENTRY
				EXPORT __main
__main
				mov 	r6, #5
				mov 	r7, #1
				
loop
				cmp		r6, #0
				ITTT	GT
				MULGT	r7, r6, r7
				SUBGT	r6, r6, #1
				BGT		loop
				
Stop			
				B	Stop
				END
					