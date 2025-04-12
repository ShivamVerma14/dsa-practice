#include <iostream>
using namespace std;

void insert(int* arr, int element, int index) {
    int i = index - 1;
    while (i >= 0 && arr[i] > element) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = element;
}

void sort(int* arr, int n) {
    if (n <= 1)
        return;

    sort(arr, n - 1);

    int last_element = arr[n - 1];
    insert(arr, last_element, n - 1);
}

int main() {
    int arr[] = {2, 5, 1, 9, 6};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}