all: Main.o Database.o GameThreads.o Mecman.o Ghost.o Character.o Map.o 
	g++ Main.o Map.o Character.o Mecman.o Ghost.o Database.o GameThreads.o -o programa -lm -lncurses -pthread
Map.o: Map.cpp
	g++ Map.cpp -c -pthread 
Character.o: Character.cpp
	g++ Character.cpp -c -pthread 
Mecman.o: Mecman.cpp
	g++ Mecman.cpp -c -pthread 
Ghost.o: Ghost.cpp
	g++ Ghost.cpp -c -pthread 
GameThreads.o: GameThreads.cpp
	g++ GameThreads.cpp -c -pthread 
Database.o: Database.cpp
	g++ Database.cpp -c
Main.o: Main.cpp
	g++ Main.cpp -c -pthread 

run:
	./programa
clean:
	rm -rf programa *.o *.gch
