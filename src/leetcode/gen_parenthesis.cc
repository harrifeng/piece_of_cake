/////////////////////////////////////////////////////////////////////////////////
// Given n pairs of parentheses, write a function to generate all combinations //
// of well-formed parentheses.                                                 //
//                                                                             //
// For example, given n = 3, a solution set is:                                //
//                                                                             //
// "((()))", "(()())", "(())()", "()(())", "()()()"                            //
/////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    void addParen(vector<string> &vec, string str, int left, int right){
        if (left == 0 && right == 0) {
            vec.push_back(str);
        }
        if (left > 0) {
            addParen(vec, str + '(', left - 1, right);
        }
        if (right > left) {
            addParen(vec, str + ')', left, right - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> result;
        string sample;
        addParen(result, sample, n, n);
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution ss;
    string result;
    vector<char> sta;
    vector<string> rr;
    rr = ss.generateParenthesis(3);
    for (int i = 0; i < rr.size(); i++) {
        cout << rr[i] << endl;
    }

    return 0;
}


