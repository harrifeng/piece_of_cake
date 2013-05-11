///////////////////////////////////////////////////////////////////////////////
// The two arrays are separated to four parts, if what we want is a median,
// then the median will locate AT MOST THREE SECTIONS! (why? because one
// quarter own at least one elements then, one quarter can not own over half
// of the elements) so in each case, we remove one quarter
//
//
// 1)if (m/2+n/2+1) >= k, then the median is likely at lower value half, then
//   left the two bigger value quarter, if one case that one array's values are
//   all bigger than the other array. so we will select the biggest quarter
//   (judged by the array[size/2], as the lower two quarters' value MUST
//   lower than them.)
// 2)if (m/2+n/2+1) < k, then the opposite side, the lowest quarter will be
//   removed.
// Note: the boundaries !!
// 1) You have to judge between k and (m/2 + n/2 + 1), not with (m+n)/2 + 1
// 2) Everytime, we drop a quarter also with one element more, as the one
//    element has already be compared with its counterpart, and can not be
//    the result!
//
// +----------------+  +----------------+
// |                |  |                |
// | A1,A2.....Am/2 |  |A(m/2+1).....Am |
// +----------------+  +----------------+
//     Quarter1            Quarter2
// +----------------+  +----------------+
// |                |  |                |
// | B2,B2.....Bn/2 |  |B(n/2+1).....Bn |      -
// +----------------+  +----------------+
//     Quarter3            Quarter4
///////////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int find_median(int a[], int m, int b[], int n, int k) {
    assert(a && b);
    if (m <= 0) {
        return b[k-1];
    }
    if (n <= 0) {
        return a[k-1];
    }
    if (k <= 1) {
        return min(a[0], b[0]);
    }
    int half = (m/2 + n/2 + 1);
    if (half >= k) {
        if (a[m/2] > b[n/2]) {
            return find_median(a, m/2, b, n, k);
        } else {
            return find_median(a, m, b, n/2, k);
        }
    } else {
        if (a[m/2] > b[n/2]) {
            int q = n/2 + 1;
            return find_median(a, m, b + q , n - q, k - q);
        } else {
            int q = m/2 + 1;
            return find_median(a + q, m - q, b, n, k - q);
        }
    }
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m + n) % 2 == 1) {
        return find_median(A, m, B, n, (m+n)/2 + 1);
    } else {
        return (find_median(A, m, B, n, (m+n)/2 + 1) +
                find_median(A, m, B, n, (m+n)/2)) / 2.0;
    }
}

int main(int argc, char *argv[]) {
    int arra[6] = {1, 3, 5, 7, 9, 11};
    int arrb[6] = {2, 4, 6, 8, 10, 12};

    cout << findMedianSortedArrays(arra, 5, arrb, 6) << endl;
    cout << findMedianSortedArrays(arra, 6, arrb, 6) << endl;
    return 0;
}
