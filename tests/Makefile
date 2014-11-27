
# All tests produced by this Makefile.  Remember to add new tests you created
# to the list.
TESTS = exec

# House-keeping build targets.

all: $(TESTS)

clean:
	-rm $(TESTS) *.o

# Points to the root of Google Test, relative to where this file is.  Remember
# to tweak this if you move this file.
GTEST_DIR = ../lib/gtest

# Flags passed to the preprocessor. Set Google Test's header directory as a
# system directory, such that the compiler doesn't generate warnings in Google
# Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++11 -O3 -DNDEBUG

LFLAGS = -Wall -std=c++11 -O3 -DNDEBUG

LIB_DIR = ../lib
GTEST_LIB = $(LIB_DIR)/gtest_main.a

SRC_DIR = ../src
OBJECTS = tests.o $(SRC_DIR)/karkkainen_sanders.o

tests.o: tests.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I../ -c tests.cpp -o $@

# Builds the test. A test should link with either gtest.a or gtest_main.a,
# depending on whether it defines its own main() function.
exec: $(OBJECTS) $(GTEST_LIB)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LFLAGS) -lpthread $^ -o $@
	./$@; #rm -f $@

