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
    ListNode* merge_two(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(0);
        head->next = l1;
        ListNode* prev = head;
        if (l1==NULL){
            head->next=l2;
        }
        while (l1!=NULL && l2!=NULL){
            if (l1->val < l2->val){
                if (l1->next != NULL){
                    prev = l1;
                    l1=l1->next;
                }else{
                    l1->next = l2;
                    break;
                }
            }else{
                ListNode* tmp = l2->next;
                prev->next = l2;
                l2->next = l1;
                prev = l2;
                l2 = tmp;
            }
        }
        delete head;
        return head->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (lists.empty()){
            return NULL;
        }
        ListNode *head = lists.back();
        lists.pop_back();
        while (!lists.empty()){
            head = merge_two(head,lists.back());
            lists.pop_back();
        }
        return head;
    }
};

class TestCase{
    vector<ListNode *> lst;
    vector<int> exp;
public:
    TestCase(vector<ListNode *>lists, vector<int>expected) : lst(lists),
                                                             exp(expected) {}
    bool test_solution(Solution *ss) {
        cout << "\n|--Test Casing------------------------------------|" << endl;
        for (int i = 0; i < lst.size(); i++) {
            ListNode *tmp = lst[i];
            while (tmp) {
                cout << tmp->val << " ";
                tmp = tmp->next;
            }
            cout << endl;
        }
        ListNode* hd = ss->mergeKLists(lst);
        ListNode* tmp = hd;

        cout << "|--Expected-->\t";
        for (int i = 0; i < exp.size(); i++) {
            cout << exp[i] << " ";
        }
        cout << endl;

        cout << "|--Output---->\t";
        while (hd) {
            cout << hd->val << " ";
            hd = hd->next;
        }
        cout << endl;

        hd = tmp;
        for (int i = 0; i < exp.size(); i++) {
            if (hd->val != exp[i]) {
                cout << "Failed!" << endl;
                return false;
            }
            hd = hd->next;
        }
        cout << "Succ!" << endl;
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
    int arr2[5] = {2, 4, 6, 8, 10};
    int arr3[5] = {3, 12, 13, 15, 234};
    int arr4[7] = {1, 11, 21, 31, 41, 51, 61};
    int arr_1[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 234};
    int arr_2[23] = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 11, 12, 13, 14, 15,
                     21, 31, 41, 51, 61, 234};
    vector<int> expected_1(arr_1, arr_1+16);
    vector<int> expected_2(arr_2, arr_2+23);

    vector<ListNode *> input;
    input.push_back(get_list(arr1, 6));
    input.push_back(get_list(arr2, 5));
    input.push_back(get_list(arr3, 5));
    TestCase *tc1 = new TestCase(input, expected_1);
    tc1->test_solution(ss);

    vector<ListNode *> input2;
    input2.push_back(get_list(arr1, 6));
    input2.push_back(get_list(arr2, 5));
    input2.push_back(get_list(arr3, 5));
    input2.push_back(get_list(arr4, 7));
    TestCase *tc2 = new TestCase(input2, expected_2);
    tc2->test_solution(ss);
    return 0;
}
