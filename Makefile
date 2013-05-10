CXX = g++
CFLAGS =
SRCFILES += src/my/helloworld.cc 
SRCFILES += src/my/worldhello.cc
SRCFILES += src/leetcode/permute.cc
SRCFILES += src/test.cc

STDOBJ=$(patsubst src%.cc,build%.out, $(SRCFILES))

all: src

src: $(STDOBJ)

build/%.out: src/%.cc
	mkdir -p $(dir $@)
	$(CXX) $< -o $@ $(CFLAGS) 

clean :
	rm -rf build
