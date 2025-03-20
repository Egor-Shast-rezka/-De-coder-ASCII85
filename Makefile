CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall -std=c++17 -Iinclude

BUILDDIR = build
BINDIR = bin

TARGET = $(BINDIR)/Start

SRCS = $(wildcard *.cpp)
OBJS_NO_TEST = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(filter-out test.cpp, $(SRCS)))
OBJS_NO_MAIN = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(filter-out main.cpp, $(SRCS)))

TEST_SRCS = test.cpp
TEST_OBJS = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(TEST_SRCS))

GTEST_LIBS = -lgtest -lgtest_main -pthread

all: $(BUILDDIR) $(BINDIR) $(TARGET)

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

$(BINDIR):
	@mkdir -p $(BINDIR)

$(TARGET): $(OBJS_NO_TEST)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILDDIR)/%.o: %.cpp
	@mkdir -p $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(BUILDDIR)/test.o $(OBJS_NO_MAIN) | $(BUILDDIR) $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/test $^ $(GTEST_LIBS)
	$(BINDIR)/test
	
$(BUILDDIR)/test.o: test.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
 
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: all clean test
