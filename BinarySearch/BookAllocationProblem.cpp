/*
Given an array 'arr' of integer numbers, where 'arr[i]' represents the number of pages in the 'ith' book. There
are 'm' number of students and the task is to allocate all the books to their students. Allocate books in such a
way that:
1. Each student gets atleast one book.
2. Each book should be allocated to a student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to 'm' students such that the maximum number of pages assigned to a student is minimum.
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool is_possible_solution(vector<int>& arr, int m, int mid) {
    int student_count = 1;
    int total_pages_allocated = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (total_pages_allocated + arr[i] <= mid)
            total_pages_allocated += arr[i];
        else {
            student_count += 1;
            if (student_count > m || arr[i] > mid)
                return false;
            total_pages_allocated = arr[i];
        }
    }

    return true;
}

int allocate_books(vector<int>& arr, int m) {
    int beg = 0;
    int end = accumulate(arr.begin(), arr.end(), 0);

    int ans = -1;

    while (beg <= end) {
        int mid = beg + (end - beg) / 2;
        
        if (is_possible_solution(arr, m, mid)) {
            ans = mid;
            end = mid - 1;
        }
        else
            beg = mid + 1;
    }

    return ans;
}

int main() {
    vector<int> arr = {12, 34, 67, 90};
    int m = 2;

    int minimum_possible_allocation = allocate_books(arr, m);
    cout << minimum_possible_allocation;

    return 0;
}