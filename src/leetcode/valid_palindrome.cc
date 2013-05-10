#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

bool is_palindrome(string s) {
    if (s.size() == 0) {
        return true;
    }
    int count = 0;
    int half = 0;
    vector<char> sta;
    
    for (int i = 0; i < s.size(); ++i) {
        if (isalnum(s[i])) {
            ++count;
        }
    }
    half = count / 2;
    int index = 0;
    while (half) {
        if (isalnum(s[index])) {
            sta.push_back(s[index]);
            --half;
        }
        ++index;
    }
    if (count % 2 != 0 ) {
        while(!isalnum(s[index])) {
            index++;
        }
        ++index;
    }
    while(index < s.size()) {
        if (isalnum(s[index])) {
            if (toupper(sta.back()) == toupper(s[index])) {
                sta.pop_back();
            } else {
                return false;
            }
        }
        ++index;
    }
    return true;
}

int main(int argc, char *argv[]) {
    printf("test is important!\n");
    string ss = "ha1 bc de, f;gK gfedcb1aH";
    cout << "ss is: [" << ss << "] and is palindrmoe is "
         << is_palindrome(ss) << endl;
    return 0;
}
