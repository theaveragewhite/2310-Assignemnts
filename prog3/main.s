.global main


main:
  push {r4-r8, lr}          // Save registers r4-r8 and lr

  // Save argc and argv
  mov r4, r0                // r4 = argc
  mov r5, r1                // r5 = argv

  // Load format string for printing number of strings
  ldr r0, =fmt1
  mov r1, r4
  bl printf

  // Load and print each argument
  ldr r0, =fmt2             // Load format string for printing strings
  ldr r1, [r5, #4]          // Load argv[1]
  ldr r0, =fmt2
  ldr r1, [r5, #8]          // Load argv[2]
  ldr r0, =fmt2
  ldr r1, [r5, #12]         // Load argv[3]


  // Convert and print argv[1]
  ldr r0, [r5, #4]          // Load argv[1]
  bl atoi                   // Convert the string in argv[1] to an integer
  mov r1, r0                // Move result of atoi to r1 (integer value)
  mov r6, r0                // Save the converted integer in r6
  ldr r0, =fmt1

  // Convert and print argv[2]
  ldr r0, [r5, #8]          // Load argv[2]
  bl atoi                   // Convert the string in argv[2] to an integer
  mov r1, r0                // Move result of atoi to r1 (integer value)
  mov r7, r0                // Save the converted integer in r7
  ldr r0, =fmt1


  // Convert and print argv[3]
  ldr r0, [r5, #12]         // Load argv[3]
  bl atoi                   // Convert the string in argv[3] to an integer
  mov r1, r0                // Move result of atoi to r1 (integer value)
  mov r8, r0                // Save the converted integer in r8
  ldr r0, =fmt1


  // Call offset function
  ldr r0, [r5, #4]          // Load argv[1]
  mov r0, r6                // Move the first integer from r6 into r1
  mov r1, r7                // Move the second integer from r7 into r1
  mov r2, r8                // Move the third integer from r8 into r1
  bl offset
  mov r3, r0                // Save the result of the offset function in r3
  mov r1, r6                // Move the first integer in r6 into r1 for printing
  mov r2, r7                // Move the first integer in r7 into r2 for printing

  // Convert each argument to integer and print
  ldr r0, =fmt3             // Load format string for printing integers
  bl printf

  // End of program
  mov r0, #0                // Return 0
  pop {r4-r8, pc}           // Restore registers and return


.section .rodata
fmt1:   .asciz ""
fmt2:   .asciz ""
fmt3:   .asciz "The offset for a[%d][%d] is %d\n"

.text
