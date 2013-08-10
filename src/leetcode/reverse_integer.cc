// 这个解法还是存在整形越界问题,可以用下面的思路来解决整形越界
// bool addition_is_safe(uint32_t a, uint32_t b) {
// 	size_t a_bits=highestOneBitPosition(a), b_bits=highestOneBitPosition(b);
// 	return (a_bits<32 && b_bits<32);
// }    
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
};

int main(int argc, char *argv[]) {
    Solution* ss = new Solution();
    int result = ss->reverse(1234567893);

    cout << result << endl;

    return 0;
}
