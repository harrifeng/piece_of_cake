//////////////////////////////////////////////////////////////////////////
// 从两个排序好的数组里面找中位数，因为中位数在奇数和偶数的时候的定义是不一样的
// 所以在总数是偶数的时候要找到half-1和half+1两个位置的数然后求平均(注意这个
// 时候除法要以2.0为底).
// 这个情况下，问题就转化成了:"从两个排序好的,大小不同的数组里面find kth element"
// 这个find_kth函数就是这一步
// 1) 我们为了方便讨论, 认为m一直小于n(这是非常好的设计方法,可以减少非常多的复杂情
//    况的讨论)
// 2) 递归算法,上来要先确定它有的三种退出递归的条件
// 3) 把k分成两个部分 partA和partB, partA最大就是k/2, partB是k减去partA, 我们
//    可以肯定的是K肯定大于任何一个part
// 4) 在a[pa-1] 小于b[pb-1]的情况下, a[0~pa-1]都不可能是K最终的值,所以华丽的删去.
//    反之亦然.最终m==0 (m-pa有可能是0)或者 k==1(k - max(k/2) 不可能直接到0的)
///////////////////////////////////////////////////////////////////////////

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    int find_kth(int a[], int m, int b[], int n, int k) {
	if (m > n) {
	    // assume m always smaller than n
	    return find_kth(b, n, a, m, k);
	}
	if (m == 0) {
	    return b[k-1];
	}
	if (k == 1) {
	    return std::min(a[0], b[0]);
	}

	int pa = min(k/2, m);
	int pb = k - pa;
	if (a[pa-1] < b[pb-1]) {
	    return find_kth(a + pa, m - pa, b, n, k - pa);
	} else {
	    return find_kth(a, m, b + pb, n - pb, k - pb);
	}
    }
public:
    double findMedianSortedArrays(int* A, int m, int* B, int n) {
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

class  TestCase{
    int *arr_a;
    int *arr_b;
    int len_a;
    int len_b;
    float exp;
public:
    TestCase(){}
    TestCase(int* a, int la, int* b, int lb, float e) : arr_a(a), len_a(la),
							arr_b(b), len_b(lb),
							exp(e){}
    void test_solution(Solution ss) {
	cout << "\n|--Test Casing------------------------------------|" << endl;
	cout << "|--Array 1: \t[";
	for (int i = 0; i < len_a; i++) {
	    cout << arr_a[i] << ",";
	}
	cout << "]" << endl;

	cout << "|--Array 2: \t[";
	for (int i = 0; i < len_b; i++) {
	    cout << arr_b[i] << ",";
	}
	cout << "]" << endl;
	cout << "|--Expected-->\t" << exp << endl;
	cout << "|--Output---->\t";
	cout << ss.findMedianSortedArrays(arr_a, len_a, arr_b, len_b) << endl;
    }
};

int main(int argc, char *argv[]) {
    // Solution* ss = new Solution();
    Solution ss;

    int arr_a[1] = {-1};
    int len_a = 0;
    int arr_b[2] = {2, 3};
    int len_b = 2;
    float ex_1 = 2.5;

    int arr_c[2] = {1, 2};
    int len_c = 2;
    int arr_d[2] = {1, 2};
    int len_d = 2;
    float ex_2 = 1.5;

    int arr_e[3] = {1, 1, 1};
    int len_e = 3;
    int arr_f[3] = {1, 1, 1};
    int len_f = 3;
    float ex_3 = 1.0;

    int arr_g[3] = {1, 2, 2};
    int len_g = 3;
    int arr_h[3] = {1, 2, 3};
    int len_h = 3;
    float ex_4 = 2.0;

    int arr_i[3] = {2, 3, 4};
    int len_i = 3;
    int arr_j[1] = {1};
    int len_j = 1;
    float ex_5 = 2.5;

    
    TestCase t1(arr_a, len_a, arr_b, len_b, ex_1);
    t1.test_solution(ss);

    TestCase t2(arr_c, len_c, arr_d, len_d, ex_2);
    t2.test_solution(ss);

    TestCase t3(arr_e, len_e, arr_f, len_f, ex_3);
    t3.test_solution(ss);

    TestCase t4(arr_g, len_g, arr_h, len_h, ex_4);
    t4.test_solution(ss);

    TestCase t5(arr_i, len_i, arr_j, len_j, ex_5);
    t5.test_solution(ss);
    
    return 0;
}
