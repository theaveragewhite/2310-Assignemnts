comment(`This program prints a Celsius to Fahrenheit conversion table')
comment(`from -40C to 120C in steps of 10 degrees.')

comment(`Initialize starting Celsius temperature and loop index')
bipush -40        comment(`Load initial Celsius value -40 onto stack')


istore_1          comment(`Store the new Celsius value in Local_1')


label(loop)       comment(`Start of loop')

bipush 10
iadd
istore_1



iconst_1
invokevirtual(1)  comment(`Print the current Celsius value without a new line (Local_1)')

istore_2          comment(`Store loop index in local register 3 (Local_3)')

iload_2           comment(`Load current Celsius value from Local_1 onto stack')

comment(`Calculate Fahrenheit equivalent')
iload_3           comment(`Load current Celsius value from Local_1 onto stack')
bipush 9          comment(`Load constant 9 onto stack')
imul              comment(`Multiply Celsius value by 9')
bipush 5          comment(`Load constant 5 onto stack')
idiv              comment(`Divide the result by 5')
bipush 32         comment(`Load constant 32 onto stack')
iadd              comment(`Add 32 to the result to complete Fahrenheit conversion')
dup               comment(`Duplicate the current Fahrenheit value for printing')
istore_3          comment(`Store the Fahrenheit value in local register 2 (Local_2)')


iconst_2
invokevirtual(2)  comment(`Print the current Fahrenheit value with a new line (Local_2)')

comment(`Increment the Celsius value by 10')


comment(`Increment loop index by 1')
iinc 1 1          comment(`Increment local register 3 (Local_3) by 1')
bipush 10         comment(`Load constant 10 onto stack')
iadd              comment(`Add 10 to the current Celsius value')


comment(`Check if loop index is less than 17 (since we want 17 iterations from -40 to 120)')
ifle(loop)
bipush 17         comment(`Load constant 17 onto stack')


return            comment(`End of program')
