#include <iostream>
using namespace std;

bool is_sorted(int arr[], int size) {
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    return is_sorted(arr + 1, size - 1);
}

int main() {
    int arr[] = {2, 4, 9, 9, 11, 13};
    int size = sizeof(arr) / sizeof(int);

    if (is_sorted(arr, size))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}