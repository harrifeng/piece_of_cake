#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void insertion_sort(int arr[], int size) {
    int tmp;

    for (int i = 1; i < size; i++) {
        int tmp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j-1] > tmp; j--) {
            arr[j] = arr[j-1];
        }
        arr[j] = tmp;
    }
}
int main(int argc, char *argv[]) {
    int array[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    insertion_sort(array, 10);
    for (int i = 0; i < 10; ++i) {
        cout << array[i] << endl;
    }
    return 0;
}
