CXX = g++
CXXFLAGS = -g -std=c++11
LDFLAGS =
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
