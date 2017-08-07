compiler: main.o
	g++ -o bin/synct bin/main.o --std=c++1y
main.o: src/main.cpp
	g++ -c -o bin/main.o src/main.cpp --std=c++1y
run:
	./bin/synct
