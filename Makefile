CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio


all: main

main: main.o robot.o jeu.o support.o mur.o porte_arme.o laser.o
	$(LD) $(LDFLAGS)  main.o robot.o jeu.o support.o mur.o porte_arme.o laser.o -o main $(LIBS)

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

jeu.o: jeu.cpp jeu.hpp
		$(CPP) $(CPPFLAGS) -c jeu.cpp

laser.o: laser.cpp laser.hpp arme.hpp
		$(CPP) $(CPPFLAGS) -c laser.cpp

porte_arme.o: porte_arme.cpp porte_arme.hpp
		$(CPP) $(CPPFLAGS) -c porte_arme.cpp

mur.o: mur.cpp mur.hpp obstacle.hpp
		$(CPP) $(CPPFLAGS) -c mur.cpp

support.o: support.cpp support.hpp
	$(CPP) $(CPPFLAGS) -c support.cpp

robot.o: robot.cpp robot.hpp entite.hpp joueur.hpp
		$(CPP) $(CPPFLAGS) -c robot.cpp

clean:
	rm -f *.o main
