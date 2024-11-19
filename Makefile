CXX = g++
CXXFLAGS = -Isrc/include -std=c++17 -g

SOURCES = main.cpp src/view.cpp src/algorithm.cpp src/grid.cpp src/controller.cpp src/sound.cpp
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
