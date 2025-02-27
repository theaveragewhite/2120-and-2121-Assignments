compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)
##-fsanitize=address -static-libasan
$(program): nQueens.cpp T4.cpp
	$(compiler) $(options) nQueens.cpp T4.cpp -o main.out

clean:
	rm *.out
