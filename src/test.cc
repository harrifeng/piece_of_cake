///////////////////////////////////////////////////////////////////////////////////
// Given a string S, find the longest palindromic substring in S. You may assume //
// that the maximum length of S is 1000, and there exists one unique longest     //
// palindromic substring.                                                        //
///////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string pre_handle(string s) {
        if (s.size() == 0) {
            return s;
        }
        string ret = "^#";
        for (int i = 0; i < s.size(); ++i)
        {
            ret.push_back(s[i]);
            ret.push_back('#');
        }
        ret.push_back('$');
        return ret;
    }
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string new_s = pre_handle(s);

        int max_id = 0;
        int max_pos = 0;
        int count[2002] = {0};
        count[0] = 1;
        int new_len = new_s.size();

        for (int i = 1; i < new_len; ++i)
        {
            if (i < max_pos)  {
                int shadow = 2 *max_id - i;
                count[i] = count[shadow];
            } else {
                count[i] = 1;
            }
            int lp = i - 1;
            int rp = i + 1;
            while (new_s[lp] == new_s[rp]) {
                count[i] += 2;
                lp--;
                rp++;
            }
            int most = rp - 1;
            if (count[i] > count[max_id]) {
                max_pos = most;
                max_id = i;
            }
        }
        int ret = 0;
        int reti = 0;
        
        for (int i = 0; i < new_len; i++) {
            // cout << i << "   \t" << new_s[i] << "   \t" << count[i] << endl;
            if (ret < count[i]) {
                ret = count[i];
                reti = i;
            }
        }
        int size = ((ret - 1) / 2 );
        string final = new_s.substr(reti - size, ret);

        string hh;
        for (int i = 0; i < final.size(); i++) {
            if (final[i] != '#') {
                hh.push_back(final[i]);
            }
        }
        return hh;
    }
};


int main(int argc, char *argv[])
{
    Solution ss;
    cout << ss.longestPalindrome("123122346556453231") << endl;
    return 0;
}


