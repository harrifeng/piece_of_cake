#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        int c_sum = num[0] + num[1] + num[num.size()-1];
        int c_val = abs(target - c_sum);
        if (c_val == 0) {
            return c_sum;
        }
        
        for (int i = 0; i < num.size() - 2; i++) {
            int beg = i+1;
            int end = num.size() - 1;

            while (beg < end) {
                int sum = num[i] + num[beg] + num[end];
                // cout << "i" << i << " " << beg << " " << end << endl;
                int val = target - sum;
                // cout << "val=>" << val << endl;
                if (val == 0) {
                    return sum;
                } else if (val > 0) {
                    beg++;
                } else {
                    end --;
                }
                if (abs(val) < c_val) {
                    c_val = abs(val);
                    c_sum = sum;
                }
            }
        }
        return c_sum;
    }
};
int main(int argc, char *argv[]) {
    vector<int> input;
    input.push_back(0);
    input.push_back(2);
    input.push_back(1);
    input.push_back(-3);

    Solution* ss = new Solution();

    cout << ss->threeSumClosest(input, 1) << endl;
    return 0;
}
