/*
You have been given a string 'str' containing either '{' or '}'.
'str' is called valid if all the brackets are balanced. Formally
for each opening bracket, there must be a closing bracket right
to it.
You want to make 'str' valid by performing some operations on it.
In one operation, you can convert '{' into '}' or vice versa, and 
the cost of one operation is 1.
Determine the minimum cost.
*/

#include <iostream>
#include <stack>
using namespace std;

int find_minimum_cost_to_balance(string str) {
    if (str.length() % 2 != 0)
        return -1;

    stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == '{')
            s.push(ch);
        else if (!s.empty() && s.top() == '{')
            s.pop();
        else
            s.push(ch); 
    }

    int closed_count = 0, open_count = 0;
    while (!s.empty()) {
        if (s.top() == '{')
            open_count++;
        else
            closed_count++;
        s.pop();
    }

    int ans = (open_count + 1) / 2 + (closed_count + 1) / 2;
    return ans;
}

int main() {
    string str = "{{{}";

    int ans = find_minimum_cost_to_balance(str);
    cout << ans;

    return 0;
}