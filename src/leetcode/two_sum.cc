#include <cstdio>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    int index;
    Node() {}
    Node(int v, int idx) : val(v), index(idx) {}
};

bool compare(const Node &lhs, const Node &rhs) {
    return lhs.val < rhs.val;
}

vector<int> twoSum(vector<int> &numbers, int target) {
    vector<Node> a;
    for (int i = 0; i < numbers.size(); ++i) {
        a.push_back(Node(numbers[i], i+1));
    }
    sort(a.begin(), a.end(), compare);

    int i = 0;
    int j = numbers.size()  - 1;

    while (i < j) {
        int sum = a[i].val + a[j].val;
        if (sum == target) {
            vector<int> ret;
            int minIndex = min(a[i].index, a[j].index);
            int maxIndex = max(a[i].index, a[j].index);
            ret.push_back(minIndex);
            ret.push_back(maxIndex);
            return ret;
        } else if (sum < target) {
            ++i;
        } else {
            --j;
        }
    }
}

int main(int argc, char *argv[]) {
    vector<int> num;
    num.push_back(2);
    num.push_back(1);
    num.push_back(19);
    num.push_back(4);
    num.push_back(4);
    num.push_back(56);
    num.push_back(90);
    num.push_back(3);

    for (vector<int>::iterator ite = num.begin(); ite < num.end(); ++ite) {
        cout << *ite << endl;
    }
    cout << "------------------" << endl;

    vector<int> show =  twoSum(num, 8);
    printf("small index is %d\n", show[0]);
    printf("big index is %d\n", show[1]);

    return 0;
}
