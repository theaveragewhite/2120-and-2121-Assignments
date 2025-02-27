compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)

$(program): IntegerArrayQueue.cpp T6.cpp
	$(compiler) $(options) IntegerArrayQueue.cpp T6.cpp -o main.out -fsanitize=address -static-libasan

clean:
	rm *.out
