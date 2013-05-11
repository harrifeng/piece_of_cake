#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int count[26];
    memset(count, -1, 26 * sizeof(int));
    int len = 0;
    int max_len = 0;
    for (int i = 0; i < 26; ++i) {
        printf("%2c  ", 97+i);
        // cout << count[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < s.size(); ++i, ++len) {
        if (count[s[i] - 'a'] >= 0) {
            for (int i = 0; i < 26; ++i) {
                printf("%2d  ", count[i]);
                // cout << count[i] << " ";
            }
            cout << endl << "--------------------------------------------------------------------------------------------------------" << endl;
            max_len = std::max(len, max_len);
            len = 0;
            i = count[s[i] - 'a'] + 1;
            memset(count , -1, 26 * sizeof(int));
        }
        count[s[i] - 'a'] = i;
    }
    return std::max(len, max_len);
}

int main(int argc, char *argv[]) {
    string str = "thgpgwkostwfhsgapkzwmzorfefwofihmoz";
    for (int i = 0; i < str.size(); ++i) {
        printf("%2d  ", i % 10);
    }
    cout << endl;
    for (int i = 0; i < str.size(); ++i) {
        printf("%2c  ", str[i]);
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << lengthOfLongestSubstring(str) << endl;
    return 0;
}

