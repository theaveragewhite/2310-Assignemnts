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

$(program): ppmDriver.c ppmUtil.c
	$(compiler) $(options) ppmDriver.c ppmUtil.c -o main.out -fsanitize=address -static-libasan -g

clean:
	rm *.out
