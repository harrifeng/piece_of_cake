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
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return (A[0] == A[1]) ? 1 : 2;
        }

        int beg = 0;
        int end = 1;
        while (end < n) {
            if (A[beg] == A[end]) {
                end++;
            } else {
                A[beg+1] = A[end];
                beg++;
                end++;
            }
        }
        return beg + 1;
    }
};


int main(int argc, char *argv[])
{
    Solution* ss = new Solution();
    int arr[] = {1, 1, 1, 1, 2, 3, 4, 5, 6, 6, 7, 7};
    int newlen = ss->removeDuplicates(arr, 12);
    cout << "new length is " << newlen << endl;
    for (int i = 0; i < newlen; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
