compiler: main.o compilerlayer.o parser.o log.o engine.o definitions.o
	g++ -o bin/synct bin/main.o bin/compilerlayer.o bin/parser.o bin/log.o bin/engine.o bin/definitions.o --std=c++1y
main.o: src/main.cpp
	g++ -c -o bin/main.o src/main.cpp --std=c++1y
compilerlayer.o: src/objects/compilerlayer.cpp src/include/compilerlayer.h
	g++ -c -o bin/compilerlayer.o src/objects/compilerlayer.cpp --std=c++1y
parser.o: src/core/parser.cpp src/include/parser.h
	g++ -c -o bin/parser.o src/core/parser.cpp --std=c++1y
log.o: src/objects/log.cpp src/include/log.h
	g++ -c -o bin/log.o src/objects/log.cpp --std=c++1y
engine.o: src/objects/engine.cpp src/include/engine.h
	g++ -c -o bin/engine.o src/objects/engine.cpp --std=c++1y
definitions.o: src/objects/definitions.cpp src/include/definitions.h
	g++ -c -o bin/definitions.o src/objects/definitions.cpp --std=c++1y
run:
	./bin/synct
