PROGRAM=nceyes

SRC=nceyes.c
OBJ=nceyes.o
HDR=nceyes.h

# DO NOT ADD OR MODIFY ANY LINES ABOVE THIS -- make source creates them

CC=gcc
WARNINGS=-Wall -Wstrict-prototypes
CFLAGS=-O2 $(WARNINGS) -g

LIBS=-lncurses			# SYSV

$(PROGRAM): $(OBJ)
	$(CC) $(LDFLAGS) $(DEFINES) -o $@ $(OBJ) $(LIBS)

clean:
	rm -f $(PROGRAM) *.o

nceyes.o: nceyes.c nceyes.h
