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
    ListNode *head = new ListNode(-1);
    ListNode *mark = head;
    int carry = 0;

    while (l1 || l2) {
	int total = (l1 ? (l1->val) : 0) + (l2 ? (l2->val) : 0) + carry;
	carry = total / 10;
	head->next = new ListNode(total % 10);
	head = head->next;

	l1 = (l1 == NULL ? NULL : l1->next);
	l2 = (l2 == NULL ? NULL : l2->next);
    }
    if (carry) {
	head->next = new ListNode(1);
    }
    head = mark ->next;
    delete mark;
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
