compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)
##-fsanitize=address -static-libasan
$(program): Grouping.cpp T1.cpp
	$(compiler) $(options) Grouping.cpp T1.cpp -o main.out -fsanitize=address -static-libasan

clean:
	rm *.out
