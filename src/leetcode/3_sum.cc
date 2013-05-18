#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        std::sort(num.begin(), num.end());
        int i = 0;
        for (i = 0; i < num.size(); ++i) {
            // if the value is equal to previous one, skip it.
            while (i > 0  && i < num.size() && num[i] == num[i-1]) {
                i++;
            }
            int front = i + 1;
            int back = num.size() - 1;
            while (front < back) {
                int sum = num[front] + num[back];
                if ((sum + num[i]) == 0) {
                    vector<int> pair;
                    pair.push_back(num[i]);
                    pair.push_back(num[front]);
                    pair.push_back(num[back]);
                    ret.push_back(pair);
                    back--;
                    front++;
                    // if the (back--) and (front++) happen to be same with
                    // their previous value, skip them.
                    while ((front < back) && (num[back] == num[back+1]) &&
                           (num[front] == num[front--])) {
                        front++;
                        back--;
                    }
                } else if ((sum + num[i]) < 0) {
                    front++;
                } else {
                    back--;
                }
            }//while
        }//for
        return ret;
    }
};

int main(int argc, char *argv[]) {
    vector<int> input;
    input.push_back(-1);
    input.push_back(0);
    input.push_back(1);
    input.push_back(2);
    input.push_back(-1);
    input.push_back(-4);

    Solution* ss = new Solution();
    vector<vector<int> > output = ss->threeSum(input);

    for (int i = 0; i < output.size(); ++i) {
        cout << output[i][0] << " " ;
        cout << output[i][1] << " " ;
        cout << output[i][2] << " " ;
        cout << endl;
    }
    return 0;
}
