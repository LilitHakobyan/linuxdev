CXX      = g++
CXXFLAGS = -Wall -g

TARGET = complex
SRCS   = main.cpp complex.cpp complex.h
OBJS   = $(SRCS:.cpp=.o)

.PHONY: clean

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o
