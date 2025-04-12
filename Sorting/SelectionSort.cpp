#include <iostream>
using namespace std;

void sort(int *arr, int n) {
    if (n == 0 || n == 1)
        return;

    int min_index = 0;
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[min_index])
            min_index = i;

    if (min_index != 0)
        swap(arr[min_index], arr[0]);

    sort(arr + 1, n - 1);
}

int main() {
    int arr[] = {2, 5, 1, 9, 6};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}