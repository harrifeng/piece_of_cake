CXX = g++
CFLAGS =

SORT_FILES += src/sort/insertion_sort.cc
SORT_FILES += src/sort/shell_sort.cc

MY_FILES += src/my/helloworld.cc 
MY_FILES += src/my/worldhello.cc
MY_FILES += src/my/level_print_btree.cc

LEET_FILES += src/leetcode/permute.cc
LEET_FILES += src/leetcode/valid_parentheses.cc
LEET_FILES += src/leetcode/valid_palindrome.cc
LEET_FILES += src/leetcode/two_sum.cc
LEET_FILES += src/leetcode/median_of_two_sorted_arrays.cc
LEET_FILES += src/leetcode/longest_substring_without_repeating_characters.cc
LEET_FILES += src/leetcode/add_two_numbers.cc
LEET_FILES += src/leetcode/remove_nth_node_from_end_of_list.cc
LEET_FILES += src/leetcode/reverse_integer.cc
LEET_FILES += src/leetcode/palindrome_number.cc
LEET_FILES += src/leetcode/letter_combinations_of_phone_number.cc
LEET_FILES += src/leetcode/longest_common_prefix.cc
LEET_FILES += src/leetcode/3_sum.cc
LEET_FILES += src/leetcode/4_sum.cc
LEET_FILES += src/leetcode/atoi.cc
LEET_FILES += src/leetcode/roman_to_int.cc
LEET_FILES += src/leetcode/int_to_roman.cc 
LEET_FILES += src/leetcode/longest_palindrome_substring.cc
LEET_FILES += src/leetcode/zigzag_conversion.cc
LEET_FILES += src/leetcode/regular_express_match.cc
LEET_FILES += src/leetcode/container_with_most_water.cc

MY_OUT=$(patsubst src/my/%.cc,build/my/%.out, $(MY_FILES))
LEET_OUT=$(patsubst src/leetcode/%.cc,build/leetcode/%.out, $(LEET_FILES))
SORT_OUT=$(patsubst src/sort/%.cc,build/sort/%.out, $(SORT_FILES))

.PHONY : all clean

all: my leet sort test

# my is an example part------------------------------
my: $(MY_OUT)

# leet is for leetcode.com example code--------------
leet : $(LEET_OUT)

# sort example summary------------------------------
sort : $(sort_OUT)

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

%.run: %.out
	@echo "<===============Output==================>"
	@./$<

clean :
	rm -rf build
