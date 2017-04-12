# Database.cpp
# DAtabase.h
# Lesson.cpp
# Lesson.h
# User.cpp
# User.h
# library.h
# main.cpp

add=-std=c++11 -g -Wall 

main.out : Database.o User.o Lesson.o main.o
	g++ Database.o User.o Lesson.o main.o -o ./../bin/main.out
main.o : main.cpp library.h Database.h Lesson.h User.h
	g++ -c main.cpp $(add)   
Database.o : Database.cpp Database.h Lesson.h User.h
	g++ -c   Database.cpp $(add) 
User.o : User.cpp User.h
	g++ -c User.cpp $(add) 
Lesson.o : Lesson.cpp Lesson.h
	g++ -c Lesson.cpp $(add) 
clean :
	rm -r *.o 
