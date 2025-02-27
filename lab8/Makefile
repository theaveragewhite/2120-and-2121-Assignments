compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)
##-fsanitize=address -static-libasan
$(program): bstSequence.cpp T12.cpp
	$(compiler) $(options) bstSequence.cpp T12.cpp -o main.out

clean:
	rm *.out
