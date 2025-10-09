#include <iostream>
using namespace std;

// Define a Stack class
class Stack {
    int top;         // Index of the top element
    int size;        // Maximum size of the stack
    int *arr;        // Dynamic array to hold stack elements

public:
    // Constructor
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1; // Empty stack
    }

    // Push operation - insert element
    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack.\n";
        }
    }

    // Pop operation - remove top element
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Nothing to pop.\n";
        } else {
            cout << arr[top--] << " popped from stack.\n";
        }
    }

    // Peek operation - view top element
    void peek() {
        if (top == -1) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Top element: " << arr[top] << endl;
        }
    }

    // Display all elements
    void display() {
        if (top == -1) {
            cout << "Stack is empty.\n";
        } else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }
};

// Main function
int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;

    Stack st(size);

    int choice, value;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            st.push(value);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.peek();
            break;
        case 4:
            st.display();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
