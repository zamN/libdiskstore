CC=g++
CXXFLAGS=-O2 -Wall
OUTFILE=test

all: $(OUTFILE)

OBJECTS:=$(patsubst %.cpp,%.o,$(wildcard *.cpp))

$(OUTFILE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -lyaml-cpp -o $(OUTFILE)

clean:
	rm -f $(OUTFILE)
	rm -f $(OBJECTS)
