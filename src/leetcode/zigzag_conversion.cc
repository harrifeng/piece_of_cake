//////////////////////////////////////////////////////////
// 下面是行数和每组数字个数的关系		        //
// 2 --> 2					        //
// 3 --> 4					        //
// 4 --> 6					        //
// 5 --> 8					        //
// 以四行为例, 每六个分成一组 模六为0,1,2,3的都好找位置 //
// 模六为4, 5的就要好好想想了			        //
// P I N  [0]   [6] [12]			        //
// ALSIG  [1][5][7] [11]			        //
// YAHR   [2][4][8] [10				        //
// P I    [3]   [9]				        //
//////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
	if (nRows <= 1) {
            return s;
        }
	string kk[nRows];
	int mod = nRows * 2 - 2;

	for (int i = 0; i < s.length(); i++) {
	    int line = i % mod;
	    if (line < nRows) {
		kk[line] += s[i];
	    } else {
		kk[mod-line] += s[i];
	    }
	}
	string ret;
	for (int i = 0; i < nRows; i++) {
	    ret += kk[i];
	}
	return ret;
    }
};

class TestCase{
    string str;
    int row;
    string exp;
public:
    TestCase(){}
    TestCase(string s, int r, string e) : str(s), row(r), exp(e) {}

    void test_solution(Solution ss) {
	string output = ss.convert(str, row);
	string result = (output == exp) ? "Correct" : "Wrong!";
        cout << "\n|--Test Casing-------------------------------|" << result << endl;
	cout << "|--Input String is : " << str << endl;
	cout << "|--Row number is   : " << row << endl;
	cout << "|--Expected-->\t" << exp << endl;
	cout << "|--Output---->\t";
	cout << output << endl;
    }
};

int main(int argc, char *argv[]) {
    Solution ss;
    TestCase t1("PAYPALISHIRING", 2, "PYAIHRNAPLSIIG");
    t1.test_solution(ss);

    TestCase t2("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
    t2.test_solution(ss);

    TestCase t3("PAYPALISHIRING", 4, "PINALSIGYAHRPI");
    t3.test_solution(ss);

    TestCase t4("A", 1, "A");
    t4.test_solution(ss);

    return 0;
}
