CXX = g++
CXXFLAGS = -std=c++11 -fopenmp -include defines.h -O2 -g
LDFLAGS = -fopenmp
SOURCES = main.cpp Board.cpp Rule.cpp Cgol.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = seagull

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) -o $@ $^

.cpp:.o
	$(CXX) $(CFLAGS) -c -o $@ $<
.PHONY: clean
	

clean:
	rm -r $(OBJECTS)
