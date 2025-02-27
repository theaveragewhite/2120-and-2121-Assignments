compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)

$(program): calculatePostfixExpression.cpp T4.cpp
	$(compiler) $(options) calculatePostfixExpression.cpp T4.cpp -o main.out -fsanitize=address -static-libasan

clean:
	rm *.out
