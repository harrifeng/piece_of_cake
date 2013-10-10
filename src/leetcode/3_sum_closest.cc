///////////////////////////////////////////////////////////////////////////////
// Given an array S of n integers, find three integers in S such that the    //
// sum is closest to a given number, target. Return the sum of the three     //
// integers. You may assume that each input would have exactly one solution. //
//     For example, given array S = {-1 2 1 -4}, and target = 1.             //
//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).         //
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3) {
            return -1;
        }
        sort(num.begin(), num.end());
        int record = 0;
        int minV = INT_MAX;
        for (int i = 0; i < num.size() - 2; i++) {
            int start = i+1;
            int end = num.size() - 1;
            while (start < end) {
                int sum = num[i] + num[start] + num[end];
                if (sum == target) {
                    minV = 0;
                    record = sum;
                    break;
                } else if (sum < target) {
                    if (target - sum < minV) {
                        minV = target-sum;
                        record = sum;
                    }
                    start++;
                } else {
                    if (sum - target < minV) {
                        minV = sum - target;
                        record = sum;
                    }
                    end--;
                }
            }
            while (i < num.size() - 1 && num[i] == num[i+1]) {
                i++;
            }
        }
        return record;
    }
};


int main(int argc, char *argv[])
{
    int arr[] = {-1, 2, 1, -4};
    vector<int> vec(arr, arr+3);
    Solution* ss = new Solution();
    cout << ss->threeSumClosest(vec, 1) << endl;
    return 0;
}
