compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)
##-fsanitize=address -static-libasan
$(program): binarySearchTree.cpp T1.cpp
	$(compiler) $(options) binarySearchTree.cpp T1.cpp -o main.out 

clean:
	rm *.out
