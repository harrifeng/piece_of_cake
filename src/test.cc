#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *tmp = head;
        for (int i = 0; i < n; ++i) {
            head = head->next;
        }
        ListNode *forward = head;
        head = tmp;
        while(forward) {
            forward = forward->next;
            head = head->next;
        }
        head->val = head->next->val;
        ListNode *todel = head->next;
        head->next = head->next->next;
        delete todel;
        return tmp;
    }
};


int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution* ss = new Solution();

    ListNode *result = ss->removeNthFromEnd(head, 2);

    while (result) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
