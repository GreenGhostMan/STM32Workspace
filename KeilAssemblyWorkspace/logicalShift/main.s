;logical shift left
					AREA theCode, CODE, READONLY
					ENTRY
					EXPORT __main
__main
				mov r0, #0x11
				lsl r1, r0, #1
				lsl r2, r1, #1
				
Stop			B Stop
				end
