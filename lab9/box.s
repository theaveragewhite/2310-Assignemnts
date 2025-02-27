/*============================================================
; Program: Struct Return
; Name: Colton Owenby
; Course: 2310
; Section: 001
; Program Number: 9
; Date: 6/14/2024
: Description: Creates a struct
 ============================================================*/
  .global main

@ New function box_init
box_init:

    push  {lr}
    sub   sp, sp, #12   @ Allocate space for three integers

    str   r1, [sp]      @ Store r1
    str   r2, [sp, #4]  @ Store r2
    str   r3, [sp, #8]  @ Store r3

    ldmia sp, {r1, r2, r3}  @ Load width, height, depth into r1, r2, r3
    stmia r0, {r1, r2, r3}  @ Store them into the structure at address r0

    add   sp, sp, #12   @ Deallocate stack space
    pop   {pc}          @ Return

init:
    push  {lr}
    sub   sp, sp, #8

    str   r1, [sp]
    str   r2, [sp, #4]

    ldmia sp, {r1, r2}
    stmia r0, {r1, r2}

    add   sp, sp, #8
    pop   {pc}

zero:
    push  {lr}
    sub   sp, sp, #8

    mov   r3, #0
    str   r3, [sp]
    str   r3, [sp, #4]

    ldmia sp, {r1, r2}
    stmia r0, {r1, r2}

    add   sp, sp, #8
    pop   {pc}

main:
    push   {lr}
    sub    sp, sp, #20  @ Allocate space for point (8 bytes) + box (12 bytes)

    mov    r0, sp
    mov    r1, #34
    mov    r2, #-3
    bl     init

    ldr    r0, =fmtstr1
    ldr    r1, [sp]
    ldr    r2, [sp, #4]
    bl     printf

    mov    r0, sp
    bl     zero

    ldr    r0, =fmtstr1
    ldr    r1, [sp]
    ldr    r2, [sp, #4]
    bl     printf


    add    r0, sp, #8   @ r0 points to the start of the box structure on stack
    mov    r1, #45      @ Set width = 45
    mov    r2, #17      @ Set height = 17
    mov    r3, #3       @ Set depth = 3
    bl     box_init


    ldr    r0, =fmtstr2
    ldr    r1, [sp, #8]  @ Load width from [sp + 8]
    ldr    r2, [sp, #12] @ Load height from [sp + 12]
    ldr    r3, [sp, #16] @ Load depth from [sp + 16]
    bl     printf

    add    sp, sp, #20  @ Deallocate space 
    pop    {pc}

fmtstr1:
    .ascii "The members of the structure dot are %d, %d\012\000"

fmtstr2:
    .ascii "The members of the structure box are %d, %d, %d\012\000"
