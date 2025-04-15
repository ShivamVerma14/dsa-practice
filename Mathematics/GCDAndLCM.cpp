#include <iostream>
using namespace std;

int find_gcd(int a, int b) {
    if (a == 0)
        return b;

    return find_gcd(b % a, a);
}

int main() {
    int a = 56, b = 12;

    int gcd = find_gcd(a, b);
    cout << gcd << endl;

    int lcm = a * b / gcd;
    cout << lcm;

    return 0;
}