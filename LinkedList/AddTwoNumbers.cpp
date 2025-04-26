#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

Node* add_two_numbers(Node* first, Node* second) {
    first = reverse(first);
    second = reverse(second);

    Node* dummy = new Node(-1);
    Node* curr = dummy;

    int carry = 0;

    while (first || second) {
        int sum = carry;

        if (first) {
            sum += first->data;
            first = first->next;
        }
        if (second) {
            sum += second->data;
            second = second->next;
        }

        carry = sum / 10;
        sum = sum % 10;

        curr->next = new Node(sum);
        curr = curr->next;
    }

    dummy->next = reverse(dummy->next);
    return dummy->next;
}

void print_num(Node* head) {
    while (head) {
        cout << head->data;
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* first = new Node(4);
    first->next = new Node(5);

    Node* second = new Node(3);
    second->next = new Node(4);
    second->next->next = new Node(5);

    Node* res = add_two_numbers(first, second);
    print_num(res);

    return 0;
}