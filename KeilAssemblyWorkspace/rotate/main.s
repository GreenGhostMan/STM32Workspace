; LOGICAL SHIFT RIGHT	
				AREA logicalShift, CODE, READONLY
				ENTRY
				EXPORT __main
__main
				mov r0,#0x11
				lsr r1, r0, #1
				lsr r2, r1, #1
				
Stop			B Stop
				end