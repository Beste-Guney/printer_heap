simulator: request.o printer.o heap.o simulator.o main.o
	   g++ main.o request.o printer.o heap.o simulator.o -o simulator

request.o: request.cpp
	   g++ -c request.cpp
simulator.o: simulator.cpp
	    g++ -c simulator.cpp

printer.o: printer.cpp
	g++ -c printer.cpp

heap.o:heap.cpp
	g++ -c heap.cpp

main.o: main.cpp
	g++ -c main.cpp