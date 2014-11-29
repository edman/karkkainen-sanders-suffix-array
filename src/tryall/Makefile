
CC = g++
CFLAGS = -c -Wall -std=c++11 -O3 -DNDEBUG
LDFLAGS = -Wall

# SOURCES = karkkainen_sanders.cpp tryall.cpp main.cpp
SOURCES = ../karkkainen_sanders.cpp tryall.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = exec

all: $(EXECUTABLE)

clean:
	-rm *.o $(EXECUTABLE)

tryall.o: tryall.cpp drittel.cpp util.h
	$(CC) $(CFLAGS) tryall.cpp

# main.o: main.cpp
# 	$(CC) $(CFLAGS) main.cpp

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	time ./$(EXECUTABLE) 10 30
	rm $(EXECUTABLE)

