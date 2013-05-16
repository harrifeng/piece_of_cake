#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct Btree {
    Btree* left;
    Btree* right;
    int val;
    Btree(int v) : val(v), left(NULL), right(NULL){}
};

void level_print(Btree* root) {
    if (!root) {
        return;
    }

    queue<Btree*> m_queue;

    m_queue.push(root);
    while (!m_queue.empty()) {
        Btree* cur = m_queue.front();
        cout << cur->val << " ";
        m_queue.pop();
        if (cur->left) {
            m_queue.push(cur->left);
        }
        if (cur->right) {
            m_queue.push(cur->right);
        }
    }
    cout << endl;
}
        
void level_print_multline(Btree* root) {
    if (!root) {
        return;
    }

    vector<Btree*> que;
    que.push_back(root);

    int cur = 0;
    int last = 1;
    while (cur < que.size()) {
        last = que.size();
        while (cur < last) {
            cout << que[cur]->val << " ";
            if (que[cur]->left) {
                que.push_back(que[cur]->left);
            }
            if (que[cur]->right) {
                que.push_back(que[cur]->right);
            }
            cur++;
        }
        cout << endl;
    }
}
    

int main(int argc, char *argv[]) {
    Btree* rt = new Btree(1);
    rt->left = new Btree(2);
    rt->right = new Btree(3);
    rt->left->left = new Btree(4);
    rt->left->right = new Btree(5);
    rt->right->left = new Btree(6);
    rt->right->right = new Btree(7);

    level_print(rt);
    level_print_multline(rt);
    return 0;
}
