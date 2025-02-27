compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)

$(program): T13.cpp
	$(compiler) $(options) T13.cpp -o main.out -fsanitize=address -static-libasan

clean:
	rm *.out
