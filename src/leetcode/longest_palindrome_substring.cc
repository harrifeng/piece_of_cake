#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

class Solution {
    string pre_process(string s) {
        int n = s.length();
        if (n == 0) {
            return "^$";
        }
        string ret = "^";
        for (int i = 0; i < n; i++) {
            ret+="#" + s.substr(i, 1);
        }
        ret += "#$";
        return ret;
    }
public:
    string longestPalindrome(string s) {
        string T = pre_process(s);
        int n = T.length();
        int *P = new int[n];
        int max_pos_id = 0;
        int max_pos = 0;
        for (int i = 1; i < n-1; i++) {
            // i's mirror position on the left
            int i_mirror = 2 * max_pos_id - i;
            P[i] = (max_pos > i) ? min(max_pos-i, P[i_mirror]) : 0;

            //to caculate the value by compare one by one
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                P[i]++;
            }

            //if you reach new most right position, replace corresponding value
            if (i + P[i] > max_pos) {
                max_pos_id = i;
                max_pos = i + P[i];
            }
        }

        int maxlen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n -1; i++) {
            if (P[i] > maxlen) {
                maxlen = P[i];
                centerIndex = i;
            }
        }
        delete[] P;
        return s.substr((centerIndex - 1 - maxlen) / 2, maxlen);
    }
};

int main(int argc, char *argv[]) {
    Solution* ss = new Solution();

    cout << ss->longestPalindrome("abcddcbaaabcd") << endl;
    return 0;
}
