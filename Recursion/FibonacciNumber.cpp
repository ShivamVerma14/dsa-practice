#include <iostream>
using namespace std;

int find_fibonacci_number(int n) {
    if (n <= 1)
        return n;

    return find_fibonacci_number(n - 1) + find_fibonacci_number(n - 2);
}

int main() {
    int n;
    cin >> n;

    int ans = find_fibonacci_number(n - 1);
    cout << ans;

    return 0;
}