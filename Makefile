CPP=g++
LD=g++

CPPFLAGS=-std=c++14
LDFLAGS=-std=c++14
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio


all: main tests

# Application

main: main.o robot.o jeu.o support.o mur.o porte_arme.o laser.o timer.o
	$(LD) $(LDFLAGS)  main.o robot.o jeu.o support.o mur.o porte_arme.o laser.o timer.o -o main $(LIBS)

main.o: main.cpp
	$(CPP) $(CPPFLAGS) -c main.cpp

jeu.o: jeu.cpp jeu.hpp
		$(CPP) $(CPPFLAGS) -c jeu.cpp

timer.o: timer.cpp timer.hpp
		$(CPP) $(CPPFLAGS) -c timer.cpp

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

# Tests

tests: tests_catch_robot.o robot.o tests_catch_support.o support.o porte_arme.o tests_catch_porte_arme.o tests_catch_mur.o mur.o tests_catch_laser.o laser.o
	$(LD) $(LDFLAGS) -o tests tests_catch_robot.o robot.o tests_catch_support.o support.o porte_arme.o tests_catch_porte_arme.o tests_catch_mur.o mur.o tests_catch_laser.o laser.o $(LIBS)

tests_catch_laser.o: tests_catch_laser.cpp laser.hpp catch.hpp
	$(CPP) $(CPPFLAGS) -c tests_catch_laser.cpp

tests_catch_mur.o: tests_catch_mur.cpp mur.hpp catch.hpp
	$(CPP) $(CPPFLAGS) -c tests_catch_mur.cpp

tests_catch_porte_arme.o: tests_catch_porte_arme.cpp porte_arme.hpp catch.hpp
	$(CPP) $(CPPFLAGS) -c tests_catch_porte_arme.cpp

tests_catch_support.o: tests_catch_support.cpp support.hpp porte_arme.hpp catch.hpp
	$(CPP) $(CPPFLAGS) -c tests_catch_support.cpp


tests_catch_robot.o: tests_catch_robot.cpp robot.hpp catch.hpp
	$(CPP) $(CPPFLAGS) -c tests_catch_robot.cpp

# Utility

clean:
	rm -f *.o main tests
