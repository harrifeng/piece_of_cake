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
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    }
};

int main(int argc, char *argv[])
{
    Solution ss;
    vector <int> vec;
    vec.push_back(1);
    vec.push_back(2);    
    cout << vec.back() << endl;
    vec.pop_back();
    cout << vec.back() << endl;    
    // cout << vec.pop_back() << endl;
    return 0;
}


