CXX = g++
CFLAGS =
SRCFILES += src/my/helloworld.cc 
SRCFILES += src/my/worldhello.cc
SRCFILES += src/leetcode/permute.cc
SRCFILES += src/leetcode/valid_parentheses.cc
SRCFILES += src/test.cc

STDOBJ=$(patsubst src%.cc,build%.out, $(SRCFILES))

all: src

src: $(STDOBJ)

build/%.out: src/%.cc
	mkdir -p $(dir $@)
	$(CXX) $< -o $@ $(CFLAGS) 

run: build/test.out
	@echo "<==========running the test.out=========>"
	@echo
	@./build/test.out
	@echo
	@echo "<==========test.out ends here===========>"
clean :
	rm -rf build
