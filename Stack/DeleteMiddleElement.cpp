#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int count, int size) {
    if (count == size / 2) {
        s.pop();
        return;
    }

    int element = s.top();
    s.pop();
    solve(s, count + 1, size);
    s.push(element);
}

void find_and_delete_middle_item(stack<int>& s) {
    int size = s.size();
    solve(s, 0, size);
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
    
    for (int i = 1; i < 6; i++)
        s.push(i);

    find_and_delete_middle_item(s);
    print_stack(s);

    return 0;
}