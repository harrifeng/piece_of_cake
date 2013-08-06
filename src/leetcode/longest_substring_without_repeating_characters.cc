///////////////////////////////////////////////////////////////////////////////
// 注意事项:
// 1) 在找最大值这种问题中, max_len可以用max_len = std:max(len, max_len)这
//    种非常简洁的表达方式
// 2) 一定不要忘了,在return的时候,在判断一次max, 因为有可能字符串以最大长度不重复结束,那么就
//    压根不会进入到else分支
// 3) memset(arr, value, sizeof(type) * size 真心难记.
//
///////////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

class Solution {
 public:
    int lengthOfLongestSubstring(string s) {
	int len = 0;
	int max_len = 0;
	int index[256];
	memset(index, -1, sizeof(int) * 256);
	for (int i = 0; i < s.size(); i++) {
	    if (index[s[i]] >= 0) {
		i = index[s[i]] + 1;
		memset(index, -1, sizeof(int) * 256);
		max_len = std::max(max_len, len);
		len = 0;
	    }
	    index[s[i]] = i;
	    len++;
	}
	return std::max(max_len, len);
    }
};

class TestCase {
    string inp;
    int    exp;
public:
    TestCase(){}
    TestCase(string input, int expect) : inp(input), exp(expect){}

    void test_solution(Solution ss) {
	cout << "\n|--Test Casing------------------------------------|" << endl;
	cout << "|---Input String : \t[";
	cout << inp << "]" << endl;
	cout << "|--Expected-->\t" << exp << endl;
	cout << "|--Output---->\t";
	cout << ss.lengthOfLongestSubstring(inp) << endl;
    }
};

int main(int argc, char *argv[]) {
    Solution ss;

    string inp1 = "abcdabcd";
    TestCase t1(inp1, 4);
    t1.test_solution(ss);

    string inp2 = "abcbaebcdef";
    TestCase t2(inp2, 5);
    t2.test_solution(ss);

    string inp3 = "abcabcbb";
    TestCase t3(inp3, 3);
    t3.test_solution(ss);
    
	
    // Solution* ss = new Solution();
    // 
    // cout << ss->lengthOfLongestSubstring("abcabcbbbc") << endl;
    return 0;
}
