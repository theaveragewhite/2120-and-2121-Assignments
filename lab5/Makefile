compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)
##-fsanitize=address -static-libasan
$(program): main.cpp stringset.cpp T21.cpp
	$(compiler) $(options) main.cpp stringset.cpp T21.cpp -o main.out -fsanitize=address -static-libasan

clean:
	rm *.out
