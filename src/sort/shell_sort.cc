#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void shell_sort(int arr[], int size) {
    int increment;
    int i;
    int j;
    for (increment = size/2; increment > 0; increment /= 2) {
        for (i = increment; i < size; i++) {
            int tmp = arr[i];
            for ( j = i; j >= increment; j-=increment) {
                if (tmp < arr[j - increment]) {
                    arr[j] = arr[j-increment];
                } else {
                    break;
                }
            }
            arr[j] = tmp;
        }
    }
}

int main(int argc, char *argv[]) {
    int array[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    shell_sort(array, 10);
    for (int i = 0; i < 10; ++i) {
        cout << array[i] << endl;
    }
    return 0;
}
