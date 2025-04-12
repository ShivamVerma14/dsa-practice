#include <iostream>
using namespace std;

int partition(int* arr, int beg, int end) {
    int pivot = arr[end];
    int i = beg - 1;

    for (int j = beg; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void sort(int* arr, int beg, int end) {
    if (beg >= end)
        return;

    int pivot_index = partition(arr, beg, end);
    sort(arr, beg, pivot_index - 1);
    sort(arr, pivot_index + 1, end);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}