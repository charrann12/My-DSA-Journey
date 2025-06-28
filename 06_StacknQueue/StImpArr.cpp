#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int topIndex;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1;
    }

    // Push operation
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++topIndex] = x;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        topIndex--;
    }

    // Top operation
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // or throw exception
        }
        return arr[topIndex];
    }

    // Check if stack is empty
    bool isEmpty() {
        return topIndex == -1;
    }

    // Check if stack is full
    bool isFull() {
        return topIndex == capacity - 1;
    }

    // Destructor to avoid memory leak
    ~Stack() {
        delete[] arr;
    }
};
