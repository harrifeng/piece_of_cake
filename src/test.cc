#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    printf("test is important!\n");
    vector<int> sta;
    sta.push_back(1);
    sta.push_back(2);
    sta.push_back(3);
    sta.push_back(4);
    sta.push_back(5);
    cout << "begin iteration------" << endl;
    for (vector<int>::iterator it = sta.begin(); it < sta.end(); ++it) {
        cout << *it << endl;
    }
    cout << "end iteration--------" << endl;

    cout << "last element is " << sta.back() << endl;
    sta.pop_back();
    cout << "after one pop back, last element is " << sta.back() << endl;
    sta.pop_back();
    cout << "after one pop back, last element is " << sta.back() << endl;
    return 0;
}
