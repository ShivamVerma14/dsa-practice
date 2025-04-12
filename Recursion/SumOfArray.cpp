#include <iostream>
using namespace std;

int find_sum(int arr[], int size) {
    if (size == 0)
        return 0;

    return arr[0] + find_sum(arr + 1, size - 1);
}

int main() {
    int arr[] = {3, 2, 5, 1, 6};
    int size = sizeof(arr) / sizeof(int);

    int sum = find_sum(arr, size);
    cout << sum;

    return 0;
}