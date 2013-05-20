#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if (num.size() < 4) {
            return ret;
        }
        std::sort(num.begin(), num.end());

        for (int i = 0; i < num.size()-3; i++) {
            if (i > 0 && num[i] == num[i-1]) {
                continue;
            }
            for (int j = i+1;j < num.size()-2;j++) {
                if (j > i+1 && num[j] == num[j-1]) {
                    continue;
                }
                int end = num.size() - 1;
                for (int beg = j+1; beg < end; beg++) {
                    if (beg > j+1 && num[beg] == num[beg-1]) {
                        continue;
                    }
                    int sum = num[i] + num[j] + num[beg] + num[end];
                    if (sum == target) {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[beg]);
                        tmp.push_back(num[end]);
                        ret.push_back(tmp);
                    } else if (sum > target) {
                        end--;
                        beg--;
                    }
                }
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    vector<int> input;
    input.push_back(-5);
    input.push_back(5);
    input.push_back(4);
    input.push_back(-3);
    input.push_back(0);
    input.push_back(0);
    input.push_back(4);
    input.push_back(2);

    Solution* ss = new Solution();
    vector<vector<int> > output = ss->fourSum(input, 4);

    for (int i = 0; i < output.size(); ++i) {
        cout << output[i][0] << " " ;
        cout << output[i][1] << " " ;
        cout << output[i][2] << " " ;
        cout << output[i][3] << " " ;
        cout << endl;
    }
    return 0;
}
