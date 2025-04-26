#include <iostream>
using namespace std;

class Node {
public:
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

bool is_palindrome(Node* head) {
    if (!head)
        return false;

    if (!head->next)
        return true;

    Node* middle = find_middle(head);
    middle->next = reverse(middle->next);

    Node* curr = head;
    Node* temp = middle->next;

    while (temp) {
        if (curr->data != temp->data) {
            middle->next = reverse(middle->next);
            return false;
        }
        curr = curr->next;
        temp = temp->next;
    }

    middle->next = reverse(middle->next);
    return true;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);

    if (is_palindrome(head))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}