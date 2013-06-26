///////////////////////////////////////////////////////////////////////////////
// 1)这个题目主要的难点在于辅助函数 find_kth的设计,这个其实是一个递归函数, 递归
//   函数上来就要设计退出的情形,在这个例子里面就是两个数组中有一个空了,或者k空了
// 2)辅助函数设计出来了,其实问题就转换成在两个已经排序好的数组中寻找第k大的数,
//   最后要根据奇偶性来分别求出中位数
//
// 注意事项:
// 1) 要比较k和(m/2 + n/2 + 1)之间的大小,而不要写成(m+n)/2 + 1, 比较的时候
//    两个数组还是以不同数组的身份开始的
// 2) 删除的时候,每次都尽量"多删一个", 比如 在find_kth(a, m/2, b, n, k)这个判断
//    中,如果m是偶数,那么正好删除了一半, 但是如果m是奇数的话,那就刚好多删了一个!
//    find_kth(a, m, b + q , n - q, k - q)这个判断中q = n/2 + 1, 如果n是偶数
//    那就多删了一个, 如果n是奇数则刚刚好删除了一半. 这个例子告诉我们在边界问题
//    上遇到要删除一半的时候, 肯定边界是多删一个没问题,多删两个就有可能错的.
// 3) 在这种删除一半一半的代码中,边界非常重要,差之毫厘谬以千里的情况就在"="情况
//    的判断,具体到这个例子 [half >= k]这句为什么不是[half > k]呢, 因为在else
//    的判断中, k要减去q, 这个时候我们要保守一点,要k足够大才去减, 在k == half
//    的情况下,很可能减不够q, 所以我们选择把k==half放到前面的逻辑里面.
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


class Solution {
    int find_kth(int a[], int m, int b[], int n, int k) {
        if (m <= 0) {
            return b[k-1];
        }
        if (n <= 0) {
            return a[k-1];
        }
        if (k <= 1) {
            return std::min(a[0], b[0]);
        }
        int half = m/2 + n/2 + 1;
        if (k <= half) {
            if (a[m/2] > b[n/2]) {
                return find_kth(a, m/2, b, n, k);
            } else {
                return find_kth(a, m, b, n/2, k);
            }
        } else {
            if (a[m/2] > b[n/2]) {
                int q = n/2 + 1;
                return find_kth(a, m, b+q, n-q, k-q);
            } else {
                int q = m/2 + 1;
                return find_kth(a+q, m-q, b, n, k-q);
            }
        }
    }
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if ((m+n) % 2 == 1) {
            return find_kth(A, m, B, n, (m+n)/2 + 1);
        } else {
            return (find_kth(A, m, B, n, (m+n)/2 + 1) +
                    find_kth(A, m, B, n, (m+n)/2)) / 2.0;
        }
    }
};

int main(int argc, char *argv[]) {
    Solution* ss = new Solution();
    int arra[6] = {1, 3, 5, 7, 9, 11};
    int arrb[6] = {2, 4, 6, 8, 10, 12};

    cout << ss->findMedianSortedArrays(arra, 5, arrb, 6) << endl;
    cout << ss->findMedianSortedArrays(arra, 6, arrb, 6) << endl;
    return 0;
}
