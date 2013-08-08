#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string pre_process(string s) {
        int n = s.length();
        if (n == 0) {
            return "^$";
        }
        string ret = "^";
	for (int i = 0; i < n; i++) {
	    ret.push_back('#');
	    ret.push_back(s[i]);
	}
        ret += "#$";
        return ret;
    }    
    string longestPalindrome(string s) {
	string nstr = pre_process(s);
	int nlen = nstr.size();
	int *ptr = new int[nlen];
	int max_id = 0;
	int max_pos = 0;

	for (int i = 1; i < nlen - 1; i++) {
	    int i_mirror = 2 * max_id - i;
	    ptr[i] = (max_pos > i) ? min(max_pos -i, ptr[i_mirror]) : 0;

	    while(nstr[i+1+ptr[i]] == nstr[i-1-ptr[i]]) {
		ptr[i]++;
	    }

	    if (i + ptr[i] > max_pos) {
		max_id = i;
		max_pos = i + ptr[i];
	    }
	}
	int maxlen = 0;
	int centerIndex = 0;
	for (int i = 1; i < nlen - 1; i++) {
	    if (ptr[i] > maxlen) {
		maxlen=ptr[i];
		centerIndex = i;
	    }
	}
	delete[] ptr;
	return s.substr((centerIndex - 1 - maxlen) / 2, maxlen);
    }
		    
};
    

int main(int argc, char *argv[]) {
    Solution ss;
    // string hh = ss.pre_process("wabccbw");
    string hh = ss.longestPalindrome("abcddcbawwwwwwwwwwa");
    cout << hh << endl;
    return 0;
}
