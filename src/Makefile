
CC = g++
CFLAGS = -c -Wall -std=c++11 -O3 -DNDEBUG
LDFLAGS = -Wall

SOURCES = karkkainen_sanders.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = exec

all: $(EXECUTABLE)

clean:
	-rm *.o $(EXECUTABLE)

karkkainen_sanders.o: karkkainen_sanders.cpp karkkainen_sanders.hpp
	$(CC) $(CFLAGS) karkkainen_sanders.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	./$(EXECUTABLE)

