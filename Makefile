CXX = g++
CXXFLAGS = -Werror -Wpedantic -Wall -std=c++17 -Iinclude

BUILDDIR = build
BINDIR = bin

TARGET = $(BINDIR)/Start

SRCS = $(wildcard *.cpp)
OBJS_NO_TEST = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(filter-out test.cpp test_random.cpp, $(SRCS)))
OBJS_NO_MAIN_AND_RAND = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(filter-out main.cpp test_random.cpp, $(SRCS)))
OBJS_NO_MAIN_AND_UNIT = $(patsubst %.cpp, $(BUILDDIR)/%.o, $(filter-out main.cpp test.cpp, $(SRCS)))

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

test: $(BUILDDIR)/test.o $(OBJS_NO_MAIN_AND_RAND) | $(BUILDDIR) $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/test $^ $(GTEST_LIBS)
	$(BINDIR)/test

test_rand: $(BUILDDIR)/test_random.o $(OBJS_NO_MAIN_AND_UNIT) | $(BUILDDIR) $(BINDIR)
	$(CXX) $(CXXFLAGS) -o $(BINDIR)/test_rand $^ $(GTEST_LIBS)
	$(BINDIR)/test_rand

$(BUILDDIR)/test.o: test.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILDDIR)/test_random.o: test_random.cpp | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@
 
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: all clean test test_rand
