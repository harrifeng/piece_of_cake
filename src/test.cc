///////////////////////////////////////////////////////////////////////////////////
// Given a string S, find the longest palindromic substring in S. You may assume //
// that the maximum length of S is 1000, and there exists one unique longest     //
// palindromic substring.                                                        //
///////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

class Solution {
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
public:    
    string longestPalindrome(string s) {
        string new_s = pre_process(s);
        int n = new_s.length();
        int *cnt = new int[n];
        int max_pos_id = 0;
        int max_pos = 0;

        for (int i = 1; i < n-1; i++) {
            int i_mirror = 2 * max_pos_id - i;
            cnt[i] = (max_pos > i) ? min(max_pos-i, cnt[i_mirror]) : 0;

            while(new_s[i + 1 + cnt[i]] == new_s[i - 1 - cnt[i]]) {
                cnt[i]++;
            }

            if (i + cnt[i] > max_pos) {
                max_pos_id = i;
                max_pos = i + cnt[i];
            }
        }
        int maxlen = 0;
        int center = 0;
        for (int i = 1; i < n - 1; i++) {
            if (cnt[i] > maxlen) {
                maxlen = cnt[i];
                center = i;
            }
        }
        delete[] cnt;
        return s.substr((center - 1 - maxlen) / 2, maxlen);
    }
};

class TestCase
{
    string inp;
    string exp;
public:
    TestCase(string input, string expected): inp(input), exp(expected){}
    void test_solution(Solution ss) {
        cout << "\n|--Test Casing------------------------------------|" << endl;
        cout << "|--Input String: \t[" << inp << "]" << endl;
        cout << "|--Expe String: \t[" << exp << "]" << endl;        
        cout << "|--Output String: \t[" << ss.longestPalindrome(inp) << "]" <<endl;
    }
};


int main(int argc, char *argv[])
{
    Solution ss;
    TestCase t1("123122346556453231", "465564");
    t1.test_solution(ss);
    TestCase t2("aaaa", "aaaa");
    t2.test_solution(ss);
    return 0;
}


