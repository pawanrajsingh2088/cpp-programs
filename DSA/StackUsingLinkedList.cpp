#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* topNode = NULL;

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
    cout << "Pushed " << value << " onto the stack.\n";
}

void pop() {
    if (topNode == NULL) {
        cout << "Stack Underflow! Cannot pop.\n";
        return;
    }
    Node* temp = topNode;
    cout << "Popped " << topNode->data << " from the stack.\n";
    topNode = topNode->next;
    delete temp;
}

void peek() {
    if (topNode == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Top element: " << topNode->data << endl;
}

void display() {
    if (topNode == NULL) {
        cout << "Stack is empty.\n";
        return;
    }
    Node* temp = topNode;
    cout << "Stack elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    return 0;
}
