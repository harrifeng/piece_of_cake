///////////////////////////////////////////////////////////////////////////////
// Given an array S of n integers, find three integers in S such that the    //
// sum is closest to a given number, target. Return the sum of the three     //
// integers. You may assume that each input would have exactly one solution. //
//     For example, given array S = {-1 2 1 -4}, and target = 1.             //
//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).         //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
    void append_par(int sl, int sr, string tmp, vector<string>& ret) {
        if (sl ==0 && sr==0) {
            ret.push_back(tmp);
            return ;
        }
        if (sl > 0)  {
            append_par(sl - 1, sr, tmp + '(', ret);
        }
        if (sr > sl) {
            append_par(sl, sr - 1, tmp + ')', ret);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<string> result;
        if (n == 0) {
            return result;
        }
        string tt;
        append_par(n, n, tt, result);
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution *ss = new Solution();
    vector<string> res = ss->generateParenthesis(3);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}


