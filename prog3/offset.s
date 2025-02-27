.text
.global offset

offset:

    mul r3, r0, r2    @ r3 = i * n
    add r3, r3, r1    @ r3 = (i * n) + j
    lsl r0, r3, #2    @ r0 = r3 << 2 (same as multiplying by 4)

    bx lr             @ Return from the function
