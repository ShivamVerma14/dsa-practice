/*
Given an array of characters chars, compress it using the following algorithm:
Begin with an empty string s. For each group of consecutive repeating characters in chars:
1. If the group's length is 1, append the character to s.
2. Otherwise, append the character followed by the group's length.

The compressed string s should not be returned separately, but instead, be stored in the input character
array chars. Note that the group lengths that are 10 or longer will be split into multiple characters in
chars.
After you are done modifying the input array, return the new length of the array. You must write an algo
that uses only constant extra space.
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char>& chars) {
    char ch = chars[0];
    int count = 1;

    int i = 0;

    for (int j = 1; j < chars.size(); j++) {
        if (ch == chars[j])
            count++;
        else {
            chars[i] = ch;
            i++;
            if (count > 1) {
                int digit_count = floor(log10(count)) + 1;
                int factor = pow(10, digit_count - 1);
                while (factor) {
                    int digit = count / factor;
                    chars[i] = digit + '0';
                    i++;
                    count = count % factor;
                    factor = factor / 10;
                }
            }
            ch = chars[j];
            count = 1;
        }
    }

    chars[i] = ch;
    i++;
    if (count > 1) {
        int digit_count = floor(log10(count)) + 1;
        int factor = pow(10, digit_count - 1);
        while (factor) {
            int digit = count / factor;
            chars[i] = digit + '0';
            i++;
            count = count % factor;
            factor = factor / 10;
        }
    }

    return i;
}

int main() {
    vector<char> chars = {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'};
    int idx = compress(chars);

    for (int i = 0; i < idx; i++)
        cout << chars[i];

    return 0;
}