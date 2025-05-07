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

void print_stack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(7);
    s.push(1);
    s.push(4);
    s.push(5);

    int num = 9;

    insert_at_bottom(s, num);
    print_stack(s);

    return 0;
}