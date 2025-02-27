/*============================================================
; Program: Reading Arguments and Indexing the Stack
; Name: Colton Owenby
; Course: 2310
; Section: 001
; Program Number: 8
; Date: 6/11/2024
: Description: Takes the average of a file
 ============================================================*/

.file "average.s"
.text
.align 2
.global main
.type main, %function

main:
    push {r4, r5, lr}   // Save registers r4, r5, and lr
    sub sp, sp, #8      // Allocate space on the stack for alignment


    mov r4, #0          // r4 will hold the sum
    mov r5, #16         // r5 will be the loop counter

loop:
    cmp r5, #0          // Compare counter with 0
    beq end_loop        // If counter == 0, exit loop
    sub r5, r5, #1      // Decrement loop counter


    ldr r0, =rdfmt      // Load address of format string into r0
    ldr r1, =input_num  // Load address to store input number into r1
    bl scanf            // Call scanf to read a number

    ldr r0, =input_num  // Load address of input number into r0
    ldr r0, [r0]        // Dereference to get the actual input number


    add r4, r4, r0      // Add r0 (input number) to r4 (sum)

    b loop              // Repeat the loop

end_loop:

    mov r0, r4          // Move sum to r0
    mov r1, #4          // Load 4 into r1 (shift count)
    asr r0, r0, r1      // Arithmetic shift right by 4 bits to divide by 16


    ldr r1, =prtfmt_avg // Load address of print format string for average into r1
    mov r1, r0          // Move the average to r1
    ldr r0, =prtfmt_avg // Load address of print format string into r0
    bl printf           // Call printf

    add sp, sp, #8      // Restore stack space
    pop {r4, r5, pc}    // Restore registers r4, r5 and return

.section .rodata
rdfmt:      .asciz "%d"
prtfmt_avg: .asciz "average is %d.%04d\n"
.section .data
input_num:  .word 0             
