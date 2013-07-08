#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
class Solution {
public:
    int atoi(const char *str) {
        int num = 0;
        int sign = 1;
        int len = strlen(str);
        int i = 0;
        while (str[i] == ' ' && i < len) {
            i++;
        }
        if (str[i] == '+') {
            i++;
        }
        if (str[i] == '-') {
            sign = -1;
            i++;
        }

        for (; i < len; i++) {
            if (str[i] == ' ') {
                break;
            }
            if (str[i] < '0' || str[i] > '9') {
                break;
            }
            if (INT_MAX / 10 < num || INT_MAX / 10 == num &&
                INT_MAX % 10 < (str[i] - '0')) {
                return (sign == -1) ? INT_MIN : INT_MAX;
                break;
            }
            num = num * 10 + str[i] - '0';
        }
        return num * sign;
    }
};

int main(int argc, char *argv[]) {
    Solution* ss = new Solution();

    cout << ss->atoi("   -12323 ") << endl;
    return 0;
}
