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
    int overflow = 0;
    ListNode *ret = NULL;
    ListNode **pnode = &ret;
    while (l1 && l2) {
        int val = l1->val + l2->val + overflow;
        overflow = val / 10;
        *pnode = new ListNode(val % 10);
        pnode = &((*pnode)->next);
        l1 = l1->next;
        l2 = l2->next;
    }
    ListNode *lremain = l1 ? l1 : l2;

    while (lremain) {
        int val = lremain->val + overflow;
        overflow = val / 10;
        *pnode = new ListNode(val % 10);
        pnode = &((*pnode)->next);
        lremain = lremain->next;
    }
    if (overflow > 0) {
        *pnode = new ListNode(overflow);
    }
    return ret;
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

