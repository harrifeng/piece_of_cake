#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cassert>
using namespace std;

class Solution {
    bool multiple_is_safe(int a, int b) {
        long long x=(unsigned long long)a*b;
        if (x>INT_MAX || x < INT_MIN) return false;
        return true;
    }    
        
public:
    int reverse(int x) {
        int new_n = 0;
        int left = 0;
            
        while (x != 0) {
            left = x % 10;
            assert(multiple_is_safe(new_n, 10)) ;
            new_n = new_n * 10 + left;
            x = x / 10;
        }
        return new_n;
    }
};

int main(int argc, char *argv[]) {
    Solution* ss = new Solution();

    cout << ss->reverse(INT_MAX-6) << endl;
    cout << ss->reverse(INT_MIN+7) << endl;    
    return 0;
}
