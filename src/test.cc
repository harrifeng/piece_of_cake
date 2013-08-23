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
    string convert(string s, int nRows) {
        if (nRows <= 1) {
            return s;
        }
        string ret;
        int modnum = nRows * 2 - 2;
        int len = s.length();
        string sum[2000];
        for (int i = 0; i < len; i++) {
            int newline = 0;
            int mod = i % modnum;
            if (mod >= nRows) {
                sum[modnum - mod].push_back(s[i]);
            } else {
                sum[mod].push_back(s[i]);
            }
        }
        for (int i = 0; i < nRows; i++) {
            ret += sum[i];
        }
        return ret;
    }
};

class TestCase
{
    string inp;
    int len;
    string exp;
public:
    TestCase(string input, int length, string expected): inp(input), len(length), exp(expected){}
    void test_solution(Solution ss) {
        string oup = ss.convert(inp, len);
        cout << "\n|--Test Casing------------------------------------|" << endl;
        cout << "|--Input String: \t[" << inp << "]" << endl;
        cout << "|--ZigZag length: \t[" << len << "]" << endl;        
        cout << "|--Expe String: \t[" << exp << "]" << endl;        
        cout << "|--Output String: \t[" << oup << "]" <<endl;
        cout << ((oup == exp) ? "Correct!" : "!!Wrong") << endl;
    }
};

int main(int argc, char *argv[])
{
    Solution ss;
    cout << ss.convert("PAYPALISHIRING", 3) << endl; 
    TestCase t1("ABCDEFGHIJKLMN", 2, "ACEGIKMBDFHJLN");
    t1.test_solution(ss);
    TestCase t2("ABCDEFGHIJKLMN", 3, "AEIMBDFHJLNCGK");
    t2.test_solution(ss);
    TestCase t3("ABCDEFGHIJKLMN", 4, "AGMBFHLNCEIKDJ");
    t3.test_solution(ss);
    return 0;
}

