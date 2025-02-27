compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)
##-fsanitize=address -static-libasan
$(program): T22.cpp
	$(compiler) $(options) T22.cpp -o main.out -fsanitize=address -static-libasan

clean:
	rm *.out
