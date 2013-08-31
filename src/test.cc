#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cassert>
#include <cmath>
using namespace std;
struct ListNode {
    ListNode* next;
    int val;
    ListNode(int value) : val(value), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int cnt = lists.size();
        ListNode *head = new ListNode(INT_MAX);
        ListNode *tmp = head;
        int index = 0;
        // int sum = (1 << cnt) - 1;
        int sum = 0;
        while(1) {
            int pivot = INT_MAX;
            for (int i = 0; i < cnt; i++) {
                if (lists[i] == NULL) {
                    sum |= (1 << i);
                    // sum++;
                    if (sum == ((1<<cnt) -1)) {
                        return tmp->next;
                    }
                } else if (lists[i]->val < pivot) {
                    head->next = lists[i];
                    index = i;
                    pivot = lists[i]->val;
                }
            }
            head = head->next;
            lists[index] = lists[index]->next;
        }
        return tmp->next;
    }
};


ListNode* get_list(int arr[], int len) {
    if (len < 2) {
        return NULL;
    }
    ListNode* hd = new ListNode(arr[0]);
    ListNode* tmp = hd;
    for (int i = 1; i < len; i++) {
        hd->next = new ListNode(arr[i]);
        hd = hd->next;
    }
    return tmp;
}

void display(ListNode* hd) {
    cout << "begin------------->" << endl;
    while (hd) {
        cout << hd->val << endl;
        hd = hd->next;
    }
    cout << "end--------------->" << endl;    
}

int main(int argc, char *argv[]) {
    Solution* ss = new Solution();
    
    int array1[3] = {1, 3, 5};
    ListNode* hd1 = get_list(array1, 3);
    display(hd1);
    
    int array2[3] = {2, 4, 7};
    ListNode* hd2 = get_list(array2, 3);
    display(hd2);
    
    vector<ListNode *> combine;
    combine.push_back(hd1);
    combine.push_back(hd2);
    
    ListNode* ret = ss->mergeKLists(combine);
    display(ret);

    // float sum = 0;
    // for (int i = 0; i < 3; i++) {
    //     sum += pow(2.0, i);
    // }
    // cout << sum << endl;
    // int aaa = 7;
    // aaa ^= (1 << 0);
    // cout << aaa << endl;
    // aaa ^= (1 << 1);
    // cout << aaa << endl;
    // aaa ^= (1 << 2);
    // cout << aaa << endl;
    // cout << (1 << 2) - 1 << endl;
    return 0;
}
