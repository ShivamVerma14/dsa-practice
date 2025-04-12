#include <iostream>
using namespace std;

int find_sqrt_int(int num) {
    int beg = 0, end = num;
    int ans = -1;

    while (beg <= end) {
        long long int mid = beg + (end - beg) / 2;

        long long int square = mid * mid;
        if (square <= num) {
            ans = mid;
            beg = mid + 1;
        }
        else
            end = mid - 1;
    }

    return ans;
}

double find_sqrt_decimal(int num, int precision, int base_integer) {
    double factor = 1;
    double ans = base_integer;

    for (int i = 0; i < precision; i++) {
        factor /= 10;
        for (double j = ans; j * j < num; j += factor)
            ans = j;
    }

    return ans;
}

double find_square_root(int num) {
    int base_integer = find_sqrt_int(num);
    return find_sqrt_decimal(num, 3, base_integer);
}

int main() {
    for (int num : {36, 24})
        cout << find_square_root(num) << endl;

    return 0;
}