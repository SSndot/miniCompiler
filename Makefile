# Makefile

CXX := g++
CXXFLAGS := -std=c++11

TARGET := compiler

SRCS := parser.cpp lexer.cpp main.cpp AST.cpp

OBJS := $(SRCS:.cpp=.o)

BISON := bison
BISONFLAGS := -d
FLEX := flex

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

parser.cpp: parser.y
	$(BISON) $(BISONFLAGS) -o $@ $<

lexer.cpp: lexer.l
	$(FLEX) -o $@ $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET) parser.hpp parser.cpp lexer.cpp