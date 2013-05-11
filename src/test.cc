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
