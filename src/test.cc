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
    ListNode *swapPairs(ListNode *head) {
        ListNode **ppre = &head;
        
        while(true) {
            ListNode *n0 = *ppre;
            if(NULL == n0) return head;
            ListNode *n1 = n0->next;
            if(NULL == n1) return head;
            
            //swap n0 and n1
            *ppre = n1;
            n0->next = n1->next;
            n1->next = n0;
            ppre = &(n0->next);
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        int count = 0;
        ListNode* tt = head;
        while(tt) {
            count++;
            tt = tt->next;
        }
        if (count < k) {
            return head;
        }
        count = 0;
        vector<ListNode*> sk;
        ListNode* tmp = head;
        while(tmp) {
            tmp = tmp->next;
            count++;
            if (count == (k-1)) {
                break;
            }
        }
        count = 0;
        while (head) {
            if (count == k-1) {
                count = 0;
                ListNode *gnext = head->next;
                ListNode *first = head;
                for (int i = 0; i < k-1; i++) {
                    head->next = sk.back();
                    head = head->next;
                    sk.pop_back();
                }
                if (!sk.empty()) {
                    sk.back()->next = first;
                    sk.pop_back();
                }
                sk.push_back(head);
                head->next = gnext;
                head = gnext;
            } else {
                count++;
                sk.push_back(head);
                head = head->next;
            }
        }
        return tmp;
    }
};


class TestCase{
    ListNode* lst;
    vector<int> exp;
public:
    TestCase(ListNode *lists, vector<int>expected) : lst(lists),
                                                             exp(expected) {}
    bool test_solution(Solution *ss) {
        cout << "\n|--Test Casing------------------------------------|" << endl;
        ListNode* tmp = lst;
        cout << "|--Input---->\t";
        while (tmp) {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout << endl;

        ListNode* hd = ss->swapPairs(lst);
        cout << "|--Output---->\t";
        while (hd) {
            cout << hd->val << " ";
            hd = hd->next;
        }
        cout << endl;

        cout << "|--Expected-->\t";
        for (int i = 0; i < exp.size(); i++) {
            cout << exp[i] << " ";
        }
        cout << endl;

        return true;
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

void display_list(ListNode *head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl << "----------------" << endl;
}


int main(int argc, char *argv[]) {
    Solution* ss = new Solution();
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    ListNode* hd = get_list(arr, 10);
    display_list(hd);
    ListNode* rt = ss->reverseKGroup(hd, 11);
    display_list(rt);
    

    return 0;
}
