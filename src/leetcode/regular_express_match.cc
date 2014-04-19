//////////////////////////////////////////////////////////
// +  这个正则表达式匹配的题目,需要理解的是*, 这个*需要在它的前面有个字
//    母比如c*意思就是1个或者多个*, 这也是为什么第一个case设置成
//    [*(p+1) != '*']
// +  题目的核心是动态规划: dp[i][j]的值分两种情况
//    (1)如果*(p+1)不是一个'*'的话, 我们当前最开始的两个字符
//       如果无法匹配, 那么返回false.如果可以匹配,那么有:
//       dp[i][j] = dp[i+1][j+1]
//    (2)如果*(p+1)是一个'*'的话,
//       - 我们当前最开始的两个字符无法匹配的话, 那么*号也无法起作
//         用了,dp[i][j] = dp[i][j+2]
//       - 我们当前最开始的两个字符串可以匹配, 那么*号的威力要一个
//         一个的检测, dp[i][j] = {dp[i][j+2], dp[i+1][j+2]....
//         dp[s和p不再相等了][j+2]}, 其中只要有一个为true,那么
//         就是true, 如果false也没关系,我们的*还可以为0个呢么..
//
//////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (strlen(p) == 0) {
            return strlen(s) == 0;
        }
        if (strlen(p) == 1) {
            return (strlen(s) == 1) && (*p == '.' || *p == *s);
        }

        // next p is *
        if (*(p+1) != '*')  {
            return (strlen(s) >= 1 && (*p == *s || *p == '.'))
                && isMatch(s+1, p+1);
        }

        // next p is not *
        if (isMatch(s, p+2)) {
            return true;
        } else {
            return (strlen(s) >= 1 && (*p == *s || *p == '.'))
                && isMatch(s+1, p);
        }
    }
};



class TestCase{
    string strs;
    string strp;
    bool exp;
public:
    TestCase(){}
    TestCase(string s, string p, bool e) : strs(s), strp(p), exp(e) {}

    void test_solution(Solution ss) {
	bool output = ss.isMatch(strs.c_str(), strp.c_str());
	string result = (output == exp) ? "Correct" : "Wrong!";
        cout << "\n|--Test Casing-------------------------------|" << result << endl;
	cout << "|--Input String A is : " << strs << endl;
	cout << "|--Input String B is : " << strp << endl;
	cout << "|--Expected-->\t" << exp << endl;
	cout << "|--Output---->\t";
	cout << output << endl << endl;
    }
};

int main(int argc, char *argv[]) {
    Solution ss;
    TestCase t1("aa", "a", false);
    t1.test_solution(ss);

    TestCase t2("aa", "aa", true);
    t2.test_solution(ss);

    TestCase t3("aaa", "c*aa", false);
    t3.test_solution(ss);

    TestCase t4("aa", "a*", true);
    t4.test_solution(ss);

    TestCase t5("aa", ".*", true);
    t5.test_solution(ss);

    TestCase t6("aa", ".*", true);
    t6.test_solution(ss);

    TestCase t7("aab", "c*a*b", true);
    t7.test_solution(ss);

    TestCase t8("abcbcd", "a.*c.*d", true);
    t8.test_solution(ss);

    return 0;
}
