#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_valid_parentheses(string s) {
    vector<char> sta;
    if (s.size() == 0) {
        return false;
    }
    sta.push_back(s[0]);

    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            sta.push_back(s[i]);
            continue;
        }
        char current = sta.back();
        if (s[i] == ')' && current != '(') {
            return false;
        }
        if (s[i] == ']' && current != '[') {
            return false;
        }
        if (s[i] == '}' && current != '{') {
            return false;
        }
        sta.pop_back();
    }

    if (sta.size() != 0) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    string p1 = "{{()}}";
    string p2 = "{{()(}{)}}";
    cout << is_valid_parentheses(p1) << endl;
    cout << is_valid_parentheses(p2) << endl;
    return 0;
}

