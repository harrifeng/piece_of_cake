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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* tmp = head;
        ListNode* even = head;
        ListNode* odd = head->next;
        head = head->next->next;
        int cnt = 2;
        while (head) {
            if (cnt % 2 == 0) {
                even->next = head;
                even = even->next;
            } else {
                odd->next = head;
                odd = odd->next;
            }
            cnt++;
            head = head->next;
        }
        even = tmp;
        odd = tmp->next;
        ListNode* ret = even;
        for (int i = 1; i < cnt; i++) {
            if (i % 2 == 0) {
                ret->next = even;
                even = even->next;
            } else {
                ret->next = odd;
                odd = odd->next;
            }
            ret = ret->next;
        }
        return ret;
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
    
    int array1[5] = {1, 2, 3, 4, 5};
    ListNode* hd1 = get_list(array1, 5);
    display(hd1);

    ListNode* sw1 = ss->swapPairs(hd1);
    display(sw1);    
    return 0;
}
