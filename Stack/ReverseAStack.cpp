#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int>& s, int num) {
    if (s.size() == 0) {
        s.push(num);
        return;
    }

    int element = s.top();
    s.pop();
    insert_at_bottom(s, num);
    s.push(element);
}

void reverse(stack<int>& s) {
    if (s.empty() || s.size() == 1)
        return;

    int element = s.top();
    s.pop();
    reverse(s);
    insert_at_bottom(s, element);
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
    s.push(4);
    s.push(7);
    s.push(9);

    print_stack(s);
    reverse(s);
    print_stack(s);

    return 0;
}