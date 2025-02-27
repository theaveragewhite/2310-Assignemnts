	.global main

main:
	push {r7, lr}
	sub sp, sp, #16
	add r7, sp, #0

	ldr r0, =0x12345678       /* put the source value in r0 */
	ldr r2, =0x7              /* put the location of the field's lsb in r2 */
	ldr r3, =0x8              /* put the size of field in r3 */

/* Beginning of your code */

	lsr r1, r0, r2      @ Logical shift right r0 by r2 bits, store in r1
	mov r4, #0xFF       @ Create mask by loading 8 bits (0xFF)
	lsl r4, r4, #24     @ Shift the mask left by 24 bits to align with the field size
	lsr r4, r4, #24 	  @ Shift the mask right by the remaining bits to align with the field size
	and r1, r1, r4      @ Apply the mask to extract the field into r1

/* End of your code */

/* show output on screen */
  ldr r0, =prt_line
	bl printf
	add r7, r7, #16
	mov sp, r7
	pop {r7, pc}

	.size main, .-main
	.section .rodata

prt_line: .asciz "0x%X\n"
