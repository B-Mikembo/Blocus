CC=gcc
TARGETS=main
CFLAGS= -Wall -ansi `pkg-config --cflags MLV`
LDFLAGS= `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS= `pkg-config --libs-only-l MLV`
OBJ= bin/main.o bin/window.o bin/menu.o bin/game.o bin/grid.o bin/draw.o bin/player.o

main : $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -g

bin/main.o : src/main.c includes/menu.h
	$(CC) -c src/main.c $(CFLAGS) -o bin/main.o -g

bin/window.o : src/window.c includes/window.h
	$(CC) -c src/window.c $(CFLAGS) -o bin/window.o -g

bin/menu.o : src/menu.c includes/window.h includes/menu.h 
	$(CC) -c src/menu.c $(CFLAGS) -o bin/menu.o -g

bin/game.o : src/game.c includes/game.h includes/window.h includes/draw.h includes/grid.h includes/player.h
	$(CC) -c src/game.c $(CFLAGS) -o bin/game.o -g

bin/grid.o : src/grid.c includes/grid.h includes/window.h 
	$(CC) -c src/grid.c $(CFLAGS) -o bin/grid.o -g

bin/draw.o : src/draw.c includes/draw.h includes/window.h includes/grid.h
	$(CC) -c src/draw.c $(CFLAGS) -o bin/draw.o -g

bin/player.o : src/player.c
	$(CC) -c src/player.c $(CFLAGS) -o bin/player.o -g
	
run : 
	./main

clean :
	rm $(TARGETS)
	rm bin/*