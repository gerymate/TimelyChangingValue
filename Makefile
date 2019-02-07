CXX=clang++
CXXFLAGS=-std=c++11 
CPPFLAGS=-I$(INCDIR) 
RM=rm -f
INCDIR=src
HEADERS=$(wildcard $(INCDIR)/*.h)
SOURCES=$(wildcard src/*.cpp)
OBJS=$(patsubst src/%.cpp,bin/%.o,$(SOURCES))
TEST_SOURCES=$(wildcard test/*.cpp)
MAJOR := 0
MINOR := 1
NAME := TimelyChangingValue
VERSION := $(MAJOR).$(MINOR)

all: test lib

lib: bin/lib$(NAME).so.$(VERSION)

test: $(TEST_SOURCES) $(HEADERS) test/doctest.h $(OBJS) 
	$(CXX) $(CXXFLAGS)$(CPPFLAGS) $(TEST_SOURCES) -o bin/unit_tests $(OBJS)
	bin/unit_tests

bin/lib$(NAME).so: bin/lib$(NAME).so.$(VERSION)
	ldconfig -v -n .
	ln -s lib$(NAME).so.$(MAJOR) lib$(NAME).so

bin/lib$(NAME).so.$(VERSION): bin/$(NAME).o
	$(CXX) -shared $< -o $@

bin/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@ 

clean:
	$(RM) bin/*.o

distclean:
	$(RM) bin/*

