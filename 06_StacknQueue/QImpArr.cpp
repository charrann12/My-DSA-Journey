#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int frontIndex;
    int rearIndex;
    int capacity;

public:
    // Constructor
    Queue(int size) {
        capacity = size;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
    }

    // push() = enqueue
    void push(int x) {
        if (isFull()) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        rearIndex++;
        arr[rearIndex] = x;
    }

    // pop() = dequeue
    void pop() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        frontIndex++;
    }

    // front() value
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    // isEmpty
    bool isEmpty() {
        return frontIndex > rearIndex;
    }

    // isFull
    bool isFull() {
        return rearIndex == capacity - 1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }
};
