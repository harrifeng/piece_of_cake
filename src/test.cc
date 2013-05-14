#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string pre = "";
        if (!strs.size()) return pre;
        for (int i = 0; i < strs[0].size(); i++) {
            pre += strs[0][i];             int j = 1;
            for (; j < strs.size(); j++) {
                if (pre != strs[j].substr(0, i+1)) break;
            }
            if (j != strs.size()) {
                pre.erase(pre.size()-1, 1);
                return pre;
            }
        }
        return pre;        
    }
};

int main(int argc, char *argv[]) {
    vector<string> input;
    input.push_back("flower");
    input.push_back("flow");
    input.push_back("flight");
    Solution* ss = new Solution();
    string result = ss->longestCommonPrefix(input);
    cout << result << endl;

    return 0;
}
