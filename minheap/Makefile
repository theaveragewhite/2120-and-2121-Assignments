compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)

$(program): minHeap.cpp T1.cpp
	$(compiler) $(options) minHeap.cpp T1.cpp -o main.out -fsanitize=address -static-libasan

clean:
	rm *.out
