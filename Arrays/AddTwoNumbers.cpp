#include <iostream>
#include <vector>
using namespace std;

vector<int> add_two_numbers(vector<int>& a, vector<int>& b) {
    vector<int> total;

    int carry = 0;
    int i = 0, j = 0;

    while (i < a.size() || j < b.size()) {
        int sum = 0;
        
        if (i < a.size()) {
            sum += a[i];
            i++;
        }

        if (j < b.size()) {
            sum += b[j];
            j++;
        }

        sum += carry;
        carry = sum / 10;
        sum = sum % 10;

        total.push_back(sum);
    }

    if (carry)
        total.push_back(carry);

    return total;
}

int main() {
    vector<int> a = {9, 9, 9};
    vector<int> b = {9, 8};

    vector<int> sum = add_two_numbers(a, b);
    for (int& num : sum)
        cout << num << " ";

    return 0;
}