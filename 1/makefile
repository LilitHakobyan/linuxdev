CXX      = g++
CXXFLAGS = -Wall -g

TARGET = complex
SRCS   = main.cpp complex.cpp
OBJS   = $(SRCS:.cpp=.o)

.PHONY: clean

all:	$(TARGET) clean

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

cleanT:
	rm -f $(TARGET)