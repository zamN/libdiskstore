CC=g++
CFLAGS=-O2 -Wall
OUTFILE=test

all: create

OBJECTS:=$(patsubst %.cpp,%.o,$(wildcard *.cpp))

create: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -lyaml-cpp -o $(OUTFILE)

clean:
	rm -f $(OUTFILE)
	rm -f $(OBJECTS)
