PROGRAM=nceyes

SRC=nceyes.c
OBJ=nceyes.o

CC=gcc
WARNINGS=-Wall
CFLAGS=-O2 $(WARNINGS) -g

LIBS=-lncurses -lm

$(PROGRAM): $(OBJ)
	$(CC) $(LDFLAGS) $(DEFINES) -o $@ $(OBJ) $(LIBS)

clean:
	rm -f $(PROGRAM) *.o

nceyes.o: nceyes.c
