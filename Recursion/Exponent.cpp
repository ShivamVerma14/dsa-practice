#include <iostream>
using namespace std;

int power(int base, int exp) {
    if (exp == 0)
        return 1;

    if (exp == 1)
        return base;

    int ans = power(base, exp / 2);
    
    if (exp % 2 == 0) {
        return ans * ans;
    } else {
        return base * ans * ans;
    }
}

int main() {
    int base, exp;
    cin >> base >> exp;

    int ans = power(base, exp);
    cout << ans;

    return 0;
}