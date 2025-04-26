#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* merge(Node* first, Node* second) {
    Node* dummy = new Node(-1);
    Node* curr = dummy;

    while (first && second) {
        if (first->data <= second->data) {
            curr->next = first;
            first = first->next;
        }
        else {
            curr->next = second;
            second = second->next;
        }
        curr = curr->next;
    }

    if (first)
        curr->next = first;
    else
        curr->next = second;

    return dummy->next;
}

void print_list(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* first = new Node(1);
    first->next = new Node(3);
    first->next->next = new Node(5);
    first->next->next->next = new Node(7);
    first->next->next->next->next = new Node(8);

    Node* second = new Node(2);
    second->next = new Node(3);
    second->next->next = new Node(4);
    second->next->next->next = new Node(6);
    second->next->next->next->next = new Node(7);

    Node* merged_list = merge(first, second);
    print_list(merged_list);

    return 0;
}