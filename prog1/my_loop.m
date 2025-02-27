;============================================================
; Program: Binary to Decimal Converter
; Name: [Your Name]
; Course: [Your Course Number]
; Section: [Your Section Number]
; Program Number: [Program Number]
; Date: [Date]
; Description: This program converts a binary number (0s and 1s)
;              into its decimal equivalent and prints the result.
;============================================================

; Define the binary number
word(N, 1101)

; Program starts here
start:  load N          ; Load the binary number into the accumulator
        store binNum    ; Store it in binNum

        clear           ; Clear the accumulator (set to 0)
        store decimal   ; Initialize the decimal value to 0

        clear
        store placeVal  ; Initialize place value to 1

; Main loop to process each binary digit
loop:   load binNum     ; Load the binary number
        div ten         ; Divide by 10 to shift right
        store binNum    ; Update the binary number
        mul ten         ; Restore the original binary number in acc
        sub binNum      ; Subtract to get the rightmost digit
        store digit     ; Store the digit

        load digit      ; Load the digit
        mul placeVal    ; Multiply by current place value
        add decimal     ; Add to the current decimal value
        store decimal   ; Store the new decimal value

        load placeVal   ; Load current place value
        mul two         ; Multiply by 2 to get the next place value
        store placeVal  ; Update the place value

        load binNum     ; Load the binary number
        jne loop        ; If binNum is not zero, continue the loop

; Output the result
        load decimal    ; Load the final decimal value
        print           ; Print the decimal value

        halt            ; Stop the program

; Data storage
binNum: .word 0         ; Storage for the binary number
decimal: .word 0        ; Storage for the decimal value
placeVal: .word 0       ; Storage for the current place value
digit: .word 0          ; Storage for the current digit

; Constants
ten: .word 10           ; Constant value 10
two: .word 2            ; Constant value 2

end start
