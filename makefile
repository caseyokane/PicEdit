
#Use gcc since we a programing in C
CC = g++

INCLUDES = 

#include the libtiff library, it's pretty important
LIBS = -ltiff

#need compiler warnings
CFLAGS = -g -c -Wall $(INCLUDES) -std=gnu++0x

SOURCES = MainP.cpp PicEdit.cpp

#Our objects will be the same file as our sources, just with .o 
OBJECTS = $(SOURCES:.cpp=.o)
	EXECUTABLE = PicEdit


all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) 
