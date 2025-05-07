#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        top = -1;
    }

    void push(int element) {
        if (top == capacity - 1) {
            throw overflow_error("Stack overflow!");
        }

        top++;
        arr[top] = element;
    }

    void pop() {
        if (is_empty()) {
            throw underflow_error("Stack underflow");
        }

        top--;
    }

    int peek() {
        if (is_empty()) {
            throw runtime_error("Stack is empty!");
        }

        return arr[top];
    }

    bool is_empty() {
        return top < 0;
    }
};