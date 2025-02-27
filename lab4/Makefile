compiler = gcc
options = -Wall
program = main.out
textfile = input.txt

all: $(program)

run: $(program)
	./$(program) $(textfile)


##use -fsanitize=address -static-libasan to check for memory leaks //input.txt input2.txt
##  -fsanitize=address -static-libasan -g
##add a build

$(program): driver.c functions.c
	$(compiler) $(options) driver.c functions.c -o main.out

clean:
	rm *.out
