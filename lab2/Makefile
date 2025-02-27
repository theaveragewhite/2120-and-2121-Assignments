compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)

$(program): infixToPostfix.cpp T19.cpp
	$(compiler) $(options) infixToPostfix.cpp T19.cpp -o main.out -fsanitize=address -static-libasan

clean:
	rm *.out
