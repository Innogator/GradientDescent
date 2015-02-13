all: main.o
	g++47 -o main.exe main.o -static && ./main.exe

main.o: main.cpp print.hpp
	g++47 -o main.o main.cpp -std=c++11 -O3 -Wall -Wextra -Werror -I. -c

clean:
	rm -f main.o main.exe