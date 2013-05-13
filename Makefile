CXX = g++
CFLAGS =

MY_FILES += src/my/helloworld.cc 
MY_FILES += src/my/worldhello.cc

LEET_FILES += src/leetcode/permute.cc
LEET_FILES += src/leetcode/valid_parentheses.cc
LEET_FILES += src/leetcode/valid_palindrome.cc
LEET_FILES += src/leetcode/two_sum.cc
LEET_FILES += src/leetcode/median_of_two_sorted_arrays.cc
LEET_FILES += src/leetcode/longest_substring_without_repeating_characters.cc
LEET_FILES += src/leetcode/add_two_numbers.cc

MY_OUT=$(patsubst src/my/%.cc,build/my/%.out, $(MY_FILES))
LEET_OUT=$(patsubst src/leetcode/%.cc,build/leetcode/%.out, $(LEET_FILES))

.PHONY : all clean

all: my leet test

# my is an example part------------------------------
my: $(MY_OUT)

# leet is for leetcode.com example code--------------
leet : $(LEET_OUT)

test : build/test.out

build/%.out: src/%.cc
	mkdir -p $(dir $@)
	$(CXX) $< -o $@ $(CFLAGS) 

# run for test.cc to show test------------------------
run: test
	@echo "<==========running the test.out=========>"
	@echo
	@./build/test.out
	@echo
	@echo "<==========test.out ends here===========>"
clean :
	rm -rf build
