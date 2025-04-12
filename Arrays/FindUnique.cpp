#include <iostream>
using namespace std;

int find_unique_number(int* arr, int n) {
    int unique = 0;
    for (int i = 0; i < n; i++) {
        unique ^= arr[i];
    }
    return unique;
}

int main() {
    int arr[] = {3, 7, 4, 2, 7, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    int unique_number = find_unique_number(arr, n);
    cout << unique_number;

    return 0;
}