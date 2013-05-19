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
        int i = 0;
        int j = num.size() - 1;
            int count = 0;

        while (j - i >= 3) {
            int sum = target - (num[i] + num[j]) ;
            // cout << "--------------" << endl;
            // cout << num[i] << endl;
            // cout << num[j] << endl;
            // cout << sum << endl;
            // cout << target << endl;
            // cout << "--------------" << endl;
            int beg = i + 1;
            int end = j - 1;

            while (beg < end) {
                if ((num[beg] + num[end]) == sum) {
                    vector<int> result;
                    result.push_back(num[i]);
                    result.push_back(num[beg]);
                    result.push_back(num[end]);
                    result.push_back(num[j]);
                    ret.push_back(result);
                    beg++;
                    end--;
                } else if ((num[beg] + num[end]) < sum) {
                    beg++;
                } else {
                    end--;
                }
            }
            if (count == 0) {
                i++;
                count++;
            } else if (count == 1) {
                j--;
                i--;
                count++;
            } else if (count == 2) {
                i++;
                count = 0;
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[]) {
    vector<int> input;
    input.push_back(1);
    input.push_back(0);
    input.push_back(-1);
    input.push_back(0);
    input.push_back(-2);
    input.push_back(2);

    Solution* ss = new Solution();
    vector<vector<int> > output = ss->fourSum(input, -1);

    for (int i = 0; i < output.size(); ++i) {
        cout << output[i][0] << " " ;
        cout << output[i][1] << " " ;
        cout << output[i][2] << " " ;
        cout << output[i][3] << " " ;
        cout << endl;
    }
    return 0;
}
