compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)
##-fsanitize=address -static-libasan
$(program):   wolfGoatCabbage.cpp
	$(compiler) $(options) wolfGoatCabbage.cpp -o main.out

clean:
	rm *.out
