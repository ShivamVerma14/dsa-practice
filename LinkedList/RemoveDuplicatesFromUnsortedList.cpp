#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

void remove_duplicates(Node* head) {
    unordered_set<int> visited;
    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        if (visited.find(curr->data) != visited.end()) {
            Node* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        else {
            visited.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
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
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next->next = new Node(5);

    remove_duplicates(head);
    print_list(head);

    return 0;
}