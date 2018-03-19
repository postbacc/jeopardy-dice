# Change this to your file with main in it.
BASE_NAME = jeopardy

# Where to find user code.
USER_DIR = .

# Flags passed to the preprocessor.
CPPFLAGS =

# Flags passed to the C++ compiler.
CXXFLAGS = -g -Wall -Wextra -std=c++11

PRIMARY_FILE = $(BASE_NAME).cpp

TEST_FILE = $(BASE_NAME)_test.cpp

MAIN_FILE = $(BASE_NAME)_main.cpp

TEST_OBJECTS = $(BASE_NAME).o $(BASE_NAME)_test.o

MAIN_OBJECTS = $(BASE_NAME).o $(BASE_NAME)_main.o 

# House-keeping build targets.

all : $(BASE_NAME)_test

test: $(BASE_NAME)_test.cpp

clean :
	rm -rf *.o *.dSYM *~ $(BASE_NAME)_test $(BASE_NAME)_main

# Interactive executable
$(BASE_NAME)_main: $(MAIN_OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $(BASE_NAME)_main $(MAIN_OBJECTS)

# Unit tests
$(BASE_NAME)_test: $(TEST_OBJECTS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $(BASE_NAME)_test $(TEST_OBJECTS)

