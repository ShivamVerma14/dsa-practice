/*
You are given three integers x, n and m. Your task is to find (x ^ n) % m.
*/

#include <iostream>
using namespace std;

int pow(int x, int n, int m) {
    int ans = 1;

    while (n) {
        if (n & 1)
            ans = (ans % m) * (x % m) % m;
        x = (x % m) * (x % m) % m;
        n = n >> 1;
    }

    return ans;
}

int main() {
    int x = 2;
    int n = 10;
    int m = 1e9 + 7;

    int ans = pow(x, n, m);
    cout << ans;

    return 0;
}