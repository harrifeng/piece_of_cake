///////////////////////////////////////////////////////////////////////////////
// 注意事项:
// 1) 在找最大值这种问题中, max_len可以用max_len = std:max(len, max_len)这
//    种非常简洁的表达方式
// 2) 如果把上面判断最大值的语句[max_len = std:max(len, max_len)]放到len++的
//    后面,那么势必是没有错误的,但是这样效率就不好. 为了提高效率,我们一般把这个
//    语句放到len被重置为0的时候,也就是下面例子的else分支中, 但是一定不要忘了,
//    在return的时候,在判断一次max, 因为有可能字符串以最大长度不重复结束,那么就
//    压根不会进入到else分支
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
        int i = 0;
        int hits[26];
        memset(hits, -1, sizeof(int) * 26);

        while (i < s.size()) {
            int prev_pos = hits[s[i] - 'a'];
            if (prev_pos < 0) {
                hits[s[i] - 'a'] = i;
                len++;
                i++;
            } else {
                memset(hits, -1, sizeof(int) * 26);
                max_len = std::max(len, max_len);
                len = 0;
                i = prev_pos + 1;
            }
        }
        // very easy to forget, they may never go to else
        return std::max(len, max_len);
    }
};

int main(int argc, char *argv[]) {
    Solution* ss = new Solution();

    cout << ss->lengthOfLongestSubstring("abcabcbbbc") << endl;
    return 0;
}
