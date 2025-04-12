#include <iostream>
using namespace std;

void swap_alternate(int* arr, int n) {
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 7, 8, 5};
    int n = sizeof(arr) / sizeof(int);

    swap_alternate(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}