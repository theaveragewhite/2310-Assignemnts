compiler = gcc
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)

$(program): hma.c
	$(compiler) $(options) hma.c -o main.out -fsanitize=address -static-libasan

clean:
	rm *.out
