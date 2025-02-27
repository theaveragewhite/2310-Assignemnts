compiler = gcc
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)

##use -fsanitize=address -static-libasan to check for memory leaks //input.txt input2.txt

$(program): driver.c src/functions.c
	$(compiler) $(options) driver.c src/functions.c -o main.out  -fsanitize=address -static-libasan 

clean:
	rm *.out
