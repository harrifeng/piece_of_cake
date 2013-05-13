#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode* result = new ListNode(-1);
    ListNode* pre = result;
    ListNode* pa = l1;
    ListNode* pb = l2;

    int carry = 0;

    while (pa != NULL || pb != NULL) {
        int av = (pa == NULL) ? 0 : pa->val;
        int bv = (pb == NULL) ? 0 : pb->val;
        ListNode* node = new ListNode((av+bv+carry) % 10);
        carry = (av+bv+carry) / 10;
        pre->next = node;
        pre = pre->next;
        pa = (pa == NULL) ? NULL : pa->next;
        pb = (pb == NULL) ? NULL : pb->next;
    }
    if (carry > 0) {
        pre->next = new ListNode(1);
    }

    pre = result->next;
    delete result;
    return pre;
}

int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);

    ListNode *another = new ListNode(5);
    another->next = new ListNode(6);
    another->next->next = new ListNode(4);

    ListNode *result = addTwoNumbers(head, another);

    while (result) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
