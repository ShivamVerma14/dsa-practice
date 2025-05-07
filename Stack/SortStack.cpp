#include <iostream>
#include <stack>
using namespace std;

void place(stack<int>& s, int num) {
    if (s.empty() || s.top() < num) {
        s.push(num);
        return;
    }

    int element = s.top();
    s.pop();
    place(s, num);
    s.push(element);
}

void sort(stack<int>& s) {
    if (s.size() == 1)
        return;

    int element = s.top();
    s.pop();
    sort(s);
    place(s, element);
}

void print_stack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(3);
    s.push(-7);
    s.push(9);
    s.push(-2);
    s.push(5);

    sort(s);
    print_stack(s);

    return 0;
}