#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* find_middle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if (!left)
        return right;
    if (!right)
        return left;

    Node* dummy = new Node(-1);
    Node* curr = dummy;

    while (left && right) {
        if (left->data <= right->data) {
            curr->next = left;
            left = left->next;
        }
        else {
            curr->next = right;
            right = right->next;
        }
        curr = curr->next;
    }

    if (left)
        curr->next = left;
    if (right)
        curr->next = right;

    return dummy->next;
}

Node* sort(Node* head) {
    if (!head || !head->next)
        return head;

    Node* middle = find_middle(head);
    Node* left = head;
    Node* right = middle->next;
    middle->next = nullptr;

    left = sort(left);
    right = sort(right);
    return merge(left, right);
}

void print_list(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    head = sort(head);
    print_list(head);

    return 0;
}
