#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int count[26];
    memset(count, -1, 26 * sizeof(int));
    int len = 0;
    int max_len = 0;

    for (int i = 0; i < s.size(); ++i, ++len) {
        if (count[s[i] - 'a'] >= 0) {
            max_len = std::max(len, max_len);
            len = 0;
            i = count[s[i] - 'a'] + 1;
            memset(count , -1, 26 * sizeof(int));
        }
        count[s[i] - 'a'] = i;
    }
    return std::max(len, max_len);
}

int main(int argc, char *argv[]) {
    cout << lengthOfLongestSubstring("abcabcbbbc") << endl;
    return 0;
}

