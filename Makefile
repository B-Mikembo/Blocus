CC=gcc
TARGETS=main
CFLAGS= -Wall -ansi `pkg-config --cflags MLV`
LDFLAGS= `pkg-config --libs-only-other --libs-only-L MLV`
LDLIBS= `pkg-config --libs-only-l MLV`
OBJ= bin/main.o bin/window.o bin/menu.o

main : $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

bin/main.o : src/main.c includes/menu.h
	$(CC) -c src/main.c $(CFLAGS) -o bin/main.o

bin/window.o : src/window.c includes/window.h
	$(CC) -c src/window.c $(CFLAGS) -o bin/window.o

bin/menu.o : src/menu.c includes/window.h includes/menu.h
	$(CC) -c src/menu.c $(CFLAGS) -o bin/menu.o

run : 
	./main

clean :
	rm $(TARGETS)
	rm bin/*