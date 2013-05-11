#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> two_sum(vector<int> &numbers, int target) {
    vector<int> result;
    int beg = 0;
    int end = numbers.size() - 1;

    while (beg < end) {
        if ((numbers[beg] + numbers[end]) == target) {
            result.push_back(beg+1);
            result.push_back(end+1);
            return result;
        } else if ((numbers[beg] + numbers[end]) > target) {
            --end;
        } else {
            ++beg;
        }
    }
    return result;
}

int main(int argc, char *argv[]) {
    vector<int> num;
    num.push_back(2);
    num.push_back(7);
    num.push_back(11);
    num.push_back(15);

    cout << num[0] << endl;
    for (vector<int>::iterator ite = num.begin(); ite < num.end(); ++ite) {
        cout << *ite << endl;
    }

    vector<int> show =  two_sum(num, 9);
    printf("show end is %d\n", show[0]);
    printf("show end is %d\n", show[1]);

    // cout << "index1 " << show[0] << "index2 " << show[1] << endl;
    
    return 0;
}
