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
    if (l1 == NULL && l2 == NULL) {
        return NULL;
    }

    ListNode *head = NULL;
    ListNode *pre = NULL;
    int flag = 0;

    while(l1 && l2) {
        ListNode *node = new ListNode(l1->val + l2->val + flag);
        flag = node->val / 10;
        node->val %= 10;

        if (head == NULL) {
            head = node;
        } else {
            pre->next = node;
        }
        pre = node;

        l1 = l1->next;
        l2 = l2->next;
    }
    ListNode *remain = l1 ? l1 : l2;

    while (remain) {
        ListNode* node = new ListNode(remain->val + flag);
        flag = node->val / 10;
        node->val % 10;

        if (head == NULL) {
            head = node;
        } else {
            pre->next = node;
        }

        pre = node;

        l1 = l1->next;
    }
    if (flag > 0) {
        ListNode * node = new ListNode(flag);
        pre->next = node;
    }
    return head;
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
