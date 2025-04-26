#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

Node* reverse_in_group(Node* head, int k) {
    if (!head)
        return nullptr;

    int count = 0;
    
    Node* curr = head;
    while (curr && count < k) {
        count++;
        curr = curr->next;
    }

    if (count < k)
        return head;

    Node* prev = nullptr;
    Node* front = nullptr;
    curr = head;
    count = 0;

    while (curr && count < k) {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
        count++;
    }

    if (front)
        head->next = reverse_in_group(front, k);

    return prev;
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

    int k = 4;

    head = reverse_in_group(head, k);
    print_list(head);

    return 0;
}