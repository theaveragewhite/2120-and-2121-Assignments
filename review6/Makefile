compiler = g++
options = -Wall
program = main.out

all: $(program)

run: $(program)
	./$(program)

$(program): testerMain.cpp review.cpp
	$(compiler) $(options) testerMain.cpp review.cpp -o main.out

clean:
	rm *.out
