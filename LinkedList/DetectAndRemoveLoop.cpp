#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* detect_loop_beginning_node(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return nullptr;

    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

void remove_loop(Node* intersection) {
    Node* curr = intersection;
    while (curr->next != intersection)
        curr = curr->next;
    curr->next = nullptr;
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
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = head->next->next;

    Node* intersection = detect_loop_beginning_node(head);

    if (intersection) {
        cout << "Loop begins at node with value: " << intersection->data << endl;
        remove_loop(intersection);
    }
    else {
        cout << "No loop has been detected." << endl;
    }

    print_list(head);
}