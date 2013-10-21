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
    void s_range(int arr[], int start, int end, int target, vector<int>& ret) {
        if (start > end) {
            return;
        }
        if (arr[start] == target) {
            ret.push_back(start);
            while (arr[start+1] == target && (start <= end)) {
                start++;
            }
            ret.push_back(start);
            return;
        }
        if (arr[end] == target) {
            ret.push_back(end);
            while (arr[end-1] == target && (start <= end) ) {
                end--;
            }
            ret.push_back(end);
            return;
        }

        int mid = (start + end) / 2;

        if (arr[mid] > target) {
            return s_range(arr, start+1, mid, target, ret);
        } else if (arr[mid] < target) {
            return s_range(arr, mid, end-1, target, ret);
        } else {
            return s_range(arr, start+1, end-1, target, ret);
        }
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        
        vector<int> ret;
        s_range(A, 0, n-1, target, ret);
        return ret;
    }    
};


int main(int argc, char *argv[])
{
    Solution* ss = new Solution();
    //          0   1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9};
    vector<int> result = ss->searchRange(arr, 20, 1);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
    return 0;
}
