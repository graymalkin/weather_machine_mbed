.align  2               		@@ - 2^n alignment (n=2)
.global delay_ns      			@@ - Symbol name for function
.code   16              		@@ - 16bit THUMB code (BOTH are required!)
.thumb_func             		@@ /
.type   delay_ns, %function  	@@ - symbol type (not req)

@@ Declaration: void delay_ns(int delay)
@@ Registers:
@@   r0: delay
delay_ns:
	lsr r0 , r3, #4				@@ Left shift r0 by 4. Divide by 16.
	loop_0:
		cmp r0, #0					@@ Compare r0 to 0
		sub r0, r0, #1				@@ Decrement R0
		nop
		bne loop_0					@@ If not true, branch back to loop_0
	bx lr
