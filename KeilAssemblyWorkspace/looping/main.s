				AREA looping, CODE, READONLY
				ENTRY
				EXPORT __main
__main
				mov r0, #0
			
loop
				CMP	r0, #10      	; check if a==4
				BEQ Stop	 		; go to end
				add r0, r0, #1 		;else increase
				B	loop		
				
Stop			
				B 	Stop
				END