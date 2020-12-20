all: main.o map.o character.o mecman.o ghost.o gamethreads.o
	gcc main.o map.o character.o mecman.o ghost.o gamethreads.o -o programa -lm
main.o: Main.cpp
	gcc Main.cpp -c
map.o: Map.cpp
	gcc Map.cpp -c
character.o: Character.cpp
	gcc Character.cpp -c
mecman.o: Mecman.cpp
	gcc Mecman.cpp -c
ghost.o: Ghost.cpp
	gcc Ghost.cpp -c
gamethreads.o: GameThreads.cpp
	gcc GameThreads.cpp -c
run:
	./programa
clean:
	rm -rf programa *.o
