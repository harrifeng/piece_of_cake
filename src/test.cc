#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        string trans[] = {"", " ", "abc", "def", "ghi", "jkl",  
                          "mno", "pqrs", "tuv", "wxyz"};  
        vector<string> set;      
        string seq;  
        Generater(trans, digits, 0, seq, set);  
        return set;  
    }  
    void Generater(string trans[], string& digits,   
                   int deep, string& result, vector<string>& set){  
        if(deep == digits.size())  
        {  
            set.push_back(result);  
            return;  
        }  
        int curDig = digits[deep] - 48;  
        for(int i =0; i < trans[curDig].size(); i++)  
        {  
            result.push_back(trans[curDig][i]);  
            Generater(trans, digits, deep+1, result, set);  
            result.resize(result.size() -1);  
        }  
    }
};

int main(int argc, char *argv[]) {
    Solution* ss = new Solution();

    vector<string> result = ss->letterCombinations("23");

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

    return 0;
}
