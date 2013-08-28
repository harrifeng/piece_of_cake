/////////////////////////////////////////////////////////////////////////
// 题目是有要求的判断一个整数是不是回文,条件是不能使用额外的存储(创建一两个变量是
// 没问题的,意思是不让你用vector, stack等)
/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
	if (x < 0){
	    return false;
	}
	int div = 1;
	while (x / div >= 10) {
	    div *= 10;
	}
	while (x != 0) {
	    int left = x / div;
	    int right = x % 10;
	    if (left != right) {
		return false;
	    }
	    x = (x % div) / 10;
	    div /= 100;
	}
	return true;
    }
};

class TestCase
{
    int num;
    bool exp;
public:
    TestCase(){}
    TestCase(int n, bool e) : num(n), exp(e){};
    void test_solution(Solution ss) {
	cout << "|--Input is--------->> " << num << endl;
	cout << "|--Expected value--->> " << (exp ? "true" : "false") << endl;
	cout << "|--Run result is---->> "
	     << (ss.isPalindrome(num) ? "true" : "false")
	     << endl << endl;
    }
};

int main(int argc, char *argv[]) {
    Solution ss;
    int num1 = 123454321;
    bool n1 = true;
    int num2 = -12344321;
    bool n2 = false;
    int num3 = INT_MAX;
    bool n3 = false;

    TestCase t1(num1, n1);
    t1.test_solution(ss);
    TestCase t2(num2, n2);
    t2.test_solution(ss);

    TestCase t3(num3, n3);
    t3.test_solution(ss);


    return 0;
}
