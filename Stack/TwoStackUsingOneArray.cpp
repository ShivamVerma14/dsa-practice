#include <iostream>
#include <stdexcept>
using namespace std;

class TwoStack {
private:
    int* arr;
    int size;
    int top1;
    int top2;

public:
    TwoStack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int num) {
        if (top2 - top1 <= 1)
            throw overflow_error("Stack overflow");

        top1++;
        arr[top1] = num;
    }

    void push2(int num) {
        if (top2 - top1 <= 1)
            throw overflow_error("Stack overflow");

        top2--;
        arr[top2] = num;
    }

    int pop1() {
        if (top1 < 0)
            throw underflow_error("Stack underflow");

        return arr[top1--];
    }

    int pop2() {
        if (top2 >= size)
            throw underflow_error("Stack underflow");

        return arr[top2++];
    }
};