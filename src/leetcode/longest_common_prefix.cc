#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string pre;
        if (strs.size() == 0) {
            return pre;
        }
        for (int i = 0; i < strs[0].size(); i++) {
            pre.push_back(strs[0][i]);
            int j = 1;
            for (; j < strs.size(); j++) {
                if (pre != strs[j].substr(0, pre.size())) {
                    break;
                }
            }
            if (j != strs.size()) {
                pre.resize(pre.size() - 1);
                return pre;
            }
        }
        return pre;
    }
};

int main(int argc, char *argv[]) {
    vector<string> input;
    input.push_back("flow");
    input.push_back("flat");
    input.push_back("fllower");
    Solution* ss = new Solution();

    string result = ss->longestCommonPrefix(input);

    cout << result << endl;
    return 0;
}
