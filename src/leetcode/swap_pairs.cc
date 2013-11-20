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

// class Solution {
// public:
//     ListNode *swapPairs(ListNode *head) {
//         ListNode **ppre = &head;
//         
//         while(true) {
//             ListNode *n0 = *ppre;
//             if(NULL == n0) return head;
//             ListNode *n1 = n0->next;
//             if(NULL == n1) return head;
//             
//             //swap n0 and n1
//             *ppre = n1;
//             n0->next = n1->next;
//             n1->next = n0;
//             ppre = &(n0->next);
//         }
//     }
// };

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode* tmp = head->next->next;
        ListNode* tmp2 = head->next;
        head->next->next = head;
        head->next = swapPairs(tmp);
        return tmp2;
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


int main(int argc, char *argv[]) {
    Solution* ss = new Solution();
    int arr1[6] = {1, 5, 7, 9, 11, 14};
    int arr2[6] = {5, 1, 9, 7, 14, 11};
    int arr3[5] = {3, 12, 13, 15, 234};
    int arr4[7] = {12, 3, 15, 13, 234};
    vector<int> expected_1(arr1, arr1+6);
    vector<int> expected_2(arr3, arr3+5);

    ListNode * input = get_list(arr2, 6);
    TestCase *tc1 = new TestCase(input, expected_1);
    tc1->test_solution(ss);

    ListNode * input2 = get_list(arr4, 5);
    TestCase *tc2 = new TestCase(input2, expected_2);
    tc2->test_solution(ss);
    
    return 0;
}
