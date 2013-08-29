#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cassert>
using namespace std;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cnt = lists.size();
        int *front = new int[cnt];
        // for (int i = 0; i < cnt; i++) {
        //     if (lists != NULL) {
        //         front[i] = 0;
        //     } else {
        //         front[i] = -1;
        //     }
        // }


        ListNode *head = new ListNode(INT_MIN);
        ListNode *tmp = head;
        int index = 0;
        int sum = 0;
        head->next->val = INT_MAX;
        while(1) {
            for (int i = 0; i < cnt; i++) {
                if (lists[front[i]] == NULL) {
                    sum++;
                    if (sum == cnt) {
                        return tmp->next;
                    }
                } else if (lists[front[i]]->val < head->next->val) {
                    head->next = lists[head[i]];
                    index = i;
                }
            }
            head = head->next;
            head[index]++;
        }



        
    }
};

int main(int argc, char *argv[]) {
    Solution* ss = new Solution();

    return 0;
}
