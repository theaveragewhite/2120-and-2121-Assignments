compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)
##-fsanitize=address -static-libasan
$(program): closestPair.cpp T1.cpp
	$(compiler) $(options) closestPair.cpp T1.cpp -o main.out -fsanitize=address -static-libasan

clean:
	rm *.out
