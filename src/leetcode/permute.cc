#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void permuteHelper(vector<int> num, int i, vector<vector<int> > &result) {
        if (i == num.size()) result.push_back(num);
        else {
            for (int j = i; j < num.size(); j++) {
                swap(num[i], num[j]);
                permuteHelper(num, i + 1, result);
                swap(num[i], num[j]);
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        permuteHelper(num, 0, result);
        return result;
    }
};

int main(int argc, char *argv[]) {
    Solution ss;
    vector<int> vec;
    vector<vector<int> > res;
    
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    res = ss.permute(vec);

    for (int i = 0; i < res.size(); i++) {
	for(int j = 0; j < res[i].size(); j++) {
	    cout << res[i][j];
	}
	cout << endl;
    }
    return 0;
}
