CC=g++
ARCH=ar
ARCHFLAGS=rvs
CFLAGS=-g -Wall -std=c++11 -Iheader/

testSrc=$(shell find "src/test/" -name "*.cpp")
testBaseName=$(shell basename -a $(testSrc))
testObj=$(addprefix obj/, $(patsubst %.cpp, %.o, $(testBaseName)))

testLib=lib/libgtest.a

header=$(shell find "header/" -name "*.hpp")
src=$(shell find "src/" -name "*.cpp")
libSrc=$(filter-out $(testSrc), $(src))
srcBaseName=$(shell basename -a $(libSrc))
obj=$(addprefix obj/, $(patsubst %.cpp, %.o, $(srcBaseName)))
vpath %.cpp $(dir $(src))

lib=bin/lib.a

bin=bin/driver

testBin=bin/test

all: prog lib test

lib: $(lib)
$(lib): $(obj)
		$(ARCH) $(ARCHFLAGS) $@ $^

$(obj):	obj/%.o: %.cpp $(header)
			$(CC) $(CFLAGS) -c $< -o $@

prog: $(bin)
$(bin): obj/Main.o $(lib)
		$(CC) $(CFLAGS) $^ -o $@

obj/Main.o: main.cpp			 
		$(CC) $(CFLAGS) -c $< -o $@

test: $(testBin)
	./bin/test

$(testBin): $(testObj) $(testLib) $(lib)
		    $(CC) $(CFLAGS) -isystem header/ -pthread $^ -o $@

$(testObj): obj/%.o: %.cpp $(lib)
		    $(CC) $(CFLAGS) -isystem header/ -c $< -o $@

clean:
	rm $(obj) bin/*

