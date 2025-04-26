#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* sort(Node* head) {
    Node* dummy_zero = new Node(-1);
    Node* dummy_one = new Node(-1);
    Node* dummy_two = new Node(-1);

    Node* zero = dummy_zero;
    Node* one = dummy_one;
    Node* two = dummy_two;

    while (head) {
        if (head->data == 0) {
            zero->next = head;
            zero = zero->next;
        }
        else if (head->data == 1) {
            one->next = head;
            one = one->next;
        }
        else {
            two->next = head;
            two = two->next;
        }
        head = head->next;
    }

    zero->next = dummy_one->next;
    one->next = dummy_two->next;
    two->next = nullptr;

    Node* new_head = dummy_zero->next;
    delete dummy_zero;
    delete dummy_one;
    delete dummy_two;

    return new_head;
}

void print_list(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);

    head = sort(head);
    print_list(head);

    return 0;
}