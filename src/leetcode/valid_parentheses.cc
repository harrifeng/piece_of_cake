#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0) {
            return true;
        }
        
        vector<char> sta;
        sta.push_back(s[0]);
        for (int i = 1; i < s.length(); i++) {
            char current = sta.back();
            
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sta.push_back(s[i]);
            }
            
            else if (s[i] == ')' && current != '(') {
                return false;
            }
            else if (s[i] == '}' && current != '{') {
                return false;
            }
            else if (s[i] == ']' && current != '[') {
                return false;
            } else { 
                sta.pop_back();
            }
        }
        if (!sta.empty()) {
            return false;
        }
        return true;
    }
};

int main(int argc, char *argv[]) {
    string p1 = "{{()}}";
    string p2 = "{{()(}{)}}";
    Solution *ss = new Solution();
    cout << ss->isValid(p1) << endl;
    cout << ss->isValid(p2) << endl;
    return 0;
}

