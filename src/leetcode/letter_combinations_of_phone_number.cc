#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    
    void get_combination(int depth, string digits, string phoneset[],
                         string& result, vector<string>& set) {
        if (depth == digits.size()) {
            set.push_back(result);
            return;
        }

        int num = digits[depth] - 48;
        for (int j = 0; j < phoneset[num].size(); j++) {
            result.push_back(phoneset[num][j]);
            get_combination(depth+1, digits, phoneset, result, set);
            result.resize(result.size() -1);
            // pop_back is c++11 feature
            // result.pop_back(); 
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string phone_set[] = {"", "", "abc", "def", "ghi", "jkl",
                                    "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ret_set;
        string im_result = "";
        get_combination(0, digits, phone_set, im_result, ret_set);
        return ret_set;
        
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
