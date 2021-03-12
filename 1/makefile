CXX      = g++
CXXFLAGS = -Wall -g
LDFLAGS  =

TARGET = complex
SRCS   = main.cpp complex.cpp
OBJS   = $(SRCS:.cpp=.o)


.PHONY: clean all

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) -o $(TARGET)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)