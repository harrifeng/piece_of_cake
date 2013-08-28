//////////////////////////////////////////////////////////////////
// + 木桶的容量取决于最小的那块, 因为从两头往中间靠的话,本来"底儿"就变小了
//   所以改变大的边会可能让容积更小, 而改变小的边可能因为更大的增长而掩盖
//   "底儿"的缩小.
// + 其实就是另一个版本的two sum
//////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
	int start = 0;
	int end = height.size() - 1;
	int max_v = INT_MIN;

	while(start < end) {
	    int contain = std::min(height[end], height[start]) * (end-start);
	    max_v = std::max(max_v, contain);

	    if (height[start] <= height[end]) {
		start++;
	    } else {
		end--;
	    }
	}
	return max_v;
    }


};

class TestCase{
    vector<int> hsum;
    int exp;
public:
    TestCase(){}
    TestCase(vector<int> h, int e) : hsum(h), exp(e) {}

    void test_solution(Solution ss) {
	int output = ss.maxArea(hsum);
	string result = (output == exp) ? "Correct" : "Wrong!";
        cout << "\n|--Test Casing-------------------------------|" << result << endl;
	cout << "|--Input Height list is : " << endl;
	for (int i = 0; i < hsum.size(); i++) {
	    cout << hsum[i] << " ";
	}
	cout << endl;
	cout << "|--Expected-->\t" << exp << endl;
	cout << "|--Output---->\t";
	cout << output << endl << endl;
    }
};

int main(int argc, char *argv[]) {
    Solution ss;

    int arr1[] = {2, 1, 5, 6, 2, 3};
    vector<int> h1(arr1, arr1+5);
    TestCase t1(h1, 8);
    t1.test_solution(ss);

    int arr2[] = {2, 12, 15, 16, 2, 3};
    vector<int> h2(arr2, arr2+5);
    TestCase t2(h2, 24);
    t2.test_solution(ss);


    int arr3[] = {3, 3, 5, 6, 3, 3};
    vector<int> h3(arr3, arr3+5);
    TestCase t3(h3, 12);
    t3.test_solution(ss);


    // TestCase t2("aa", "aa", true);
    // t2.test_solution(ss);
    //
    // TestCase t3("aaa", "c*aa", false);
    // t3.test_solution(ss);
    //
    // TestCase t4("aa", "a*", true);
    // t4.test_solution(ss);
    //
    // TestCase t5("aa", ".*", true);
    // t5.test_solution(ss);
    //
    // TestCase t6("aa", ".*", true);
    // t6.test_solution(ss);
    //
    // TestCase t7("aab", "c*a*b", true);
    // t7.test_solution(ss);
    //
    // TestCase t8("abcbcd", "a.*c.*d", true);
    // t8.test_solution(ss);

    return 0;
}
