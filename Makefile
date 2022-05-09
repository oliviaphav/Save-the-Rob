CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio


all: main

main: main.o robot.o support.o laser.o
	$(LD) $(LDFLAGS)  main.o robot.o support.o laser.o -o main $(LIBS)

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

laser.o: laser.cpp laser.hpp
	$(CPP) $(CPPFLAGS) -c laser.cpp

support.o: support.cpp support.hpp
	$(CPP) $(CPPFLAGS) -c support.cpp

robot.o: robot.cpp robot.hpp
		$(CPP) $(CPPFLAGS) -c robot.cpp

clean:
	rm -f *.o main
