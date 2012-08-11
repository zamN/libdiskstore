CC=g++
CXXFLAGS=-O2 -Wall
OUTFILE=test

all: $(OUTFILE)

OBJECTS:=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
SHA2=sha2/sha2.c

$(OUTFILE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(SHA2) -lyaml-cpp -o $(OUTFILE)

clean:
	rm -f $(OUTFILE)
	rm -f $(OBJECTS)
	rm -f $(SHA2)
