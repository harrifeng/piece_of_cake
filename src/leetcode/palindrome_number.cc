#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int new_n = 0;
        int left = 0;
        while (x != 0) {
            left = x % 10;
            new_n = new_n * 10 + left;
            x = x / 10;
        }
        return new_n;
    }
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int rev_x = reverse(x);
        return (rev_x == x);
    }    
};

int main(int argc, char *argv[]) {
    Solution* ss = new Solution();
    int result = ss->isPalindrome(1234321);
    cout << result << endl;

    return 0;
}
