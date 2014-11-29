CC = g++
CFLAGS = -c -w -std=c++11 -O3 -DNDEBUG
LDFLAGS = -w

SOURCES = driver.cpp
OBJECTS = $(SOURCES:.cpp=.o) ../karkkainen_sanders.o
EXECUTABLE = exec

all: $(EXECUTABLE)

clean:
	-rm *.o $(EXECUTABLE)

driver.o: driver.cpp
	$(CC) $(CFLAGS) driver.cpp

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $(EXECUTABLE)
	./$(EXECUTABLE) 1 < tin
	./$(EXECUTABLE) 0 < tin
	# -rm $(EXECUTABLE)

