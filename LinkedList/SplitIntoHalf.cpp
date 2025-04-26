/*
Given a circular linked list, split it into two circular linked lists.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void print_circular_linked_list(Node* head) {
    Node* curr = head;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
}

pair<Node*, Node*> split_into_two(Node* head) {
    Node* curr = head;
    Node* last_node = curr;
    int length = 0;

    do {
        length++;
        last_node = curr;
        curr = curr->next;
    } while (curr != head);

    for (int i = 0; i < ceil(length / 2.0) - 1; i++)
        curr = curr->next;
    
    Node* second_head = curr->next;
    curr->next = head;
    last_node->next = second_head;

    return {head, second_head};
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = head;

    print_circular_linked_list(head);

    pair<Node*, Node*> splits = split_into_two(head);

    print_circular_linked_list(splits.first);
    print_circular_linked_list(splits.second);

    return 0;
}