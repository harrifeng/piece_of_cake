///////////////////////////////////////////////////////////////////////////////
// 如下图 1)j是i关于id的对称 2) mx是当前已知的最右边的值（n+p[n]最大的值）
//
// p[j] == 7                          p[i] == 7  
//       mx_mirror       j(2*mx -i)     id               i          mx
// =========+----------+----------------+----------------+----------+=========
//              765432101234567                   765432101234567            
// 第一种情况，j的值只有7，这15个数字都被cover在[mx_mirror,id]这个区间里面，那么右边
// 的i也能保证有7个。 因为[mx_mirror, id]和[id, mx]是对称的。
///////////////////////////////////////////////////////////////////////////////
// 
//                  p[j] == 12                      p[i] >= 10
//       mx_mirror  j(2*mx -i)         id               i        mx   
// =========+---------+----------------+----------------+---------+=========
//        21X9876543210123456789X12           X9876543210123456789X??
// 第二种情况，j的值有12，但是有两个是在mx_mirror之前，同样在右侧mx只能保证10之前的肯
// 定是对称的。超过mx的部分有可能对，也有可能错。所以p[i]先赋值mx-i=10，再去比较mx+1
// 和mx+2
///////////////////////////////////////////////////////////////////////////////
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
