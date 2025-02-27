/*============================================================
; Program: Reading Arguments and Indexing the Stack
; Name: Colton Owenby
; Course: 2310
; Section: 001
; Program Number: 8
; Date: 6/11/2024
: Description: Takes the sum of a file
 ============================================================*/
    .file "sum.s"
    .text
    .align  2
    .global main
    .type   main, %function


main:
    push {r4, r5, lr}  // Save registers r4, r5, and link register (lr) to the stack
                       // r4: will be used to hold the sum
                       // r5: will be used as a loop counter
    //Code goes here
    // Initialize sum to 0
    mov r4, #0         // Set r4 to 0, which will accumulate the sum

    // Initialize loop counter to 10
    mov r5, #10        // Set r5 to 10, to control the loop for 10 iterations

loop:
    sub r5, r5, #1     // Decrement the loop counter
    cmp r5, #0         // Compare the loop counter with 0
    blt end_loop       // If the counter is less than 0, exit the loop

    ldr r0, =rdfmt     // Load the address of the format string "%d" into r0
    ldr r1, =input_num // Load the address of input_num into r1
    bl scanf           // Call scanf to read an integer from stdin
    ldr r1, =input_num // The integer read will be stored at the address pointed by r1
    ldr r0, [r1]       // Load the integer value from input_num into r0


    add r4, r4, r0     // Add the value in r0 to r4

    b loop             // Branch back to the start of the loop

end_loop:
    mov r1, r4         // Move the final sum from r4 to r1 (as the first argument to printf)
    ldr r0, =prtfmt    // Load the address of the format string "sum is %d\n" into r0

    bl printf          // Call printf to print the sum

    pop {r4, r5, pc}   // Restore registers r4, r5 and the return address from the stack
                       // The 'pop {pc}' will automatically return to the caller

.section    .rodata
rdfmt:       .asciz "%d"
prtfmt:      .asciz "sum is %d\n"

.section .data
input_num:   .word 0
