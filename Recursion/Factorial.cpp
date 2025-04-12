#include <iostream>
using namespace std;

int find_factorial(int n) {
    if (n == 0)
        return 1;

    return n * find_factorial(n - 1);
}

int main() {
    int n;
    cin >> n;
    
    int factorial = find_factorial(n);
    cout << factorial;

    return 0;
}