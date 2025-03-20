CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall -std=c++17 -I.

BUILDDIR = build
BINDIR = bin

TARGET = $(BINDIR)/Start

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(SRCS))
OBJS_NO_MAIN = $(filter-out $(BUILDDIR)/main.o, $(OBJS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $(BUILDDIR)/main.o $(OBJS_NO_MAIN)

$(BUILDDIR)/%.o: %.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: all clean
