#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
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
            //////////////////////////////////////////////////////////////
            // 这里其实用到了c语言的逻辑判断.如果第一个部分是true的话||
            // 后面的部分就不会再看了.所以其实是(1)||(2&&3)这样一种
            // 逻辑结构
            //////////////////////////////////////////////////////////////
            if (INT_MAX / 10 < num ||
                INT_MAX / 10 == num &&
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
    Solution ss;
    cout << ss.atoi("2147483647") << endl;
    cout << ss.atoi("2147483648") << endl;
    cout << ss.atoi("-2147483648") << endl;
    cout << ss.atoi("-2147483649") << endl;
    return 0;
}
