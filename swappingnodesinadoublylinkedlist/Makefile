compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)

$(program): doublyLinkedSwap.cpp T6.cpp
	$(compiler) $(options) doublyLinkedSwap.cpp T6.cpp -o main.out 

clean:
	rm *.out
