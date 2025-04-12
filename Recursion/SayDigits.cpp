#include <iostream>
using namespace std;

void say_digits(int num, string digits[]) {
    if (num == 0)
        return;

    int digit = num % 10;
    num = num / 10;

    say_digits(num, digits);
    cout << digits[digit] << " ";
}

int main() {
    int num;
    cin >> num;

    if (num == 0) {
        cout << "zero";
    } else {
        string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        say_digits(num, digits);
    }

    cout << endl;
    return 0;
}