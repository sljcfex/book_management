EXE = lib
SRC= main.c interface.c admini.c book_management.c user.c userop.c
CC=gcc
CFLAGS= -std=c99 -Wall
CLINK=
OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE)

clean:
	del $(OBJ) $(EXE)

main.o:      main.c interface.h
interface.o:   interface.c book_management.h interface.h user.h
book_management.o:   book_management.c book_management.h
admini.o:    admini.c book_management.h admini.h
user.o:	user.c user.h userop.h  admini.h
userop.o: 		userop.c book_management.h userop.h user.h
	