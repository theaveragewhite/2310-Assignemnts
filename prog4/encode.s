/*============================================================
; Program: Message Encoder
; Name: Colton Owenby
; Course: 2310
; Section: 001
; Program Number: Program 4
; Date: 6/20/2024
: Description: Encodes a character array using a Vigenere cipher in the C file
 ============================================================*/

.text
.global encode

encode:
    push {r4-r8, lr}            // Save registers and link register

    mov r4, r0                  // r4 = address of input string
    mov r5, r1                  // r5 = address of output string
    mov r6, r2                  // r6 = address of key string
    mov r7, r3                  // r7 = encode/decode switch (0 = encode, 1 = decode)
    mov r8, r2                  // r8 = save starting address of key string


next_char:
    ldrb r0, [r4]               // Load input character
    add r4, r4, #1              // Move to next input character

    cmp r0, #0                  // Check for end of input string (null terminator)
    beq done                    // If end, exit loop

    ldrb r1, [r6]               // Load key character
    cmp r1, #0                  // Check if the key character is the null terminator
    moveq r6, r8                // If the key ended, reset the key pointer to the start of the key string
    ldreqb r1, [r6]             // Load the first key character again if the end was reached
    add r6, r6, #1              // Move to next key character
    cmp r0, #' '                // Check if character is a space
    beq handle_space            // If space, handle separately
    cmp r1, #' '                // Handle space
    beq handle_space

    sub r0, r0, #0x60            // Convert input character to 0-based index (0-25)
    sub r1, r1, #0x60           // Convert key character to 0-based index (0-25)

    cmp r7, #1                  // Check if encoding or decoding
    beq decode_char             // If 0, encode
    b encode_char               // If 1, decode

encode_char:
    add r0, r0, r1              // Add key value to input value
    cmp r0, #26                 // Check if the result is greater than or equal to 26
    subgt r0, r0, #26           // If it is, wrap around by subtracting 26
    add r0, #0x60               // Convert back to ASCII character

    strb r0, [r5], #1           // Store encoded character in output
    b next_char                 // Process next character

decode_char:
    sub r0, r0, r1              // Subtract key value from input value
    cmp r0, #0                  // Check if the result is negative
    addle r0, r0, #26           // If it is, wrap around by adding 26
    add r0, #0x60               // Convert back to ASCII character

    strb r0, [r5], #1           // Store decoded character in output
    b next_char                 // Process next character

skip_encode:
    strb r7, [r1,r5]
    add r4, r4, #1   // Increment input string index
    add r5, r5, #1   // Increment output string index
    b next_char

handle_space:
    strb r0, [r5], #1           // Copy space directly to output
    b next_char                 // Process next character

done:
    strb r0, [r5]               // Null-terminate the output string
    pop {r4-r8, pc}             // Restore registers and return
