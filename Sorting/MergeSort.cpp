#include <iostream>
using namespace std;

void merge(int* arr, int beg, int mid, int end) {
    int size = end - beg + 1;
    int* temp = new int[size];

    int left = beg;
    int right = mid + 1;
    int curr = 0;

    while (left <= mid && right <= end) {
        if (arr[left] <= arr[right]) {
            temp[curr] = arr[left];
            left++;
        } else {
            temp[curr] = arr[right];
            right++;
        }
        curr++;
    }

    while (left <= mid) {
        temp[curr] = arr[left];
        left++;
        curr++;
    }

    while (right <= end) {
        temp[curr] = arr[right];
        right++;
        curr++;
    }

    for (int i = beg; i <= end; i++) {
        arr[i] = temp[i - beg];
    }
}

void sort(int* arr, int beg, int end) {
    if (beg >= end)
        return;

    int mid = beg + (end - beg) / 2;
    sort(arr, beg, mid);
    sort(arr, mid + 1, end);
    merge(arr, beg, mid, end);
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}