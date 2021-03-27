CC=gcc
TARGETS=main
CFLAGS= -Wall -ansi `pkg-config --cflags MLV`
LDFLAGS= `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS= `pkg-config --libs-only-l MLV`
OBJ= bin/main.o bin/window.o bin/menu.o bin/game.o

main : $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -g

bin/main.o : src/main.c includes/menu.h
	$(CC) -c src/main.c $(CFLAGS) -o bin/main.o -g

bin/window.o : src/window.c includes/window.h
	$(CC) -c src/window.c $(CFLAGS) -o bin/window.o -g

bin/menu.o : src/menu.c includes/window.h includes/menu.h 
	$(CC) -c src/menu.c $(CFLAGS) -o bin/menu.o -g

bin/game.o : src/game.c includes/game.h includes/window.h 
	$(CC) -c src/game.c $(CFLAGS) -o bin/game.o -g

run : 
	./main

clean :
	rm $(TARGETS)
	rm bin/*