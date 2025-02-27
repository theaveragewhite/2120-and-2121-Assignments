compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)

$(program): anagram.cpp
	$(compiler) $(options) anagram.cpp  -o main.out

clean:
	rm *.out
