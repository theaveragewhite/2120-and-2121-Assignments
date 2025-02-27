compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)
##-fsanitize=address -static-libasan
$(program): tspRefine.cpp T1.cpp
	$(compiler) $(options) tspRefine.cpp T1.cpp -o main.out

clean:
	rm *.out
