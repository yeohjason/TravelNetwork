travel: travel_network.o airport.o myList.o filename.o
	g++ -o proj6 travel_network.o airport.o myList.o filename.o

travel_network.o: travel_network.cpp airport.h
	g++ -c travel_network.cpp

airport.o: airport.cpp airport.h
	g++ -c airport.cpp

myList.o: myList.cpp airport.h
	g++ -c myList.cpp

filename.o: filename.cpp airport.h
	g++ -c filename.cpp

clean:
	rm travel travel_network.o airport.o myList.o filename.o
